#ifndef IFORCE2D_ROTATE_TO_ANGLE_H
#define IFORCE2D_ROTATE_TO_ANGLE_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_rotate_to_angle : public Test
{
public:

    //for allowing user to switch methods at runtime
    enum rotateMethod {
        RM_SET_VELOCITY,
        RM_APPLY_TORQUE,
        RM_APPLY_IMPULSE,
    };

    iforce2d_rotate_to_angle() {
        //body definition
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;

        //hexagonal shape definition
        b2PolygonShape polygonShape;
        b2Vec2 vertices[6];
        for (int i = 0; i < 6; i++) {
            float angle = -i/6.0 * 360 * DEGTORAD;
            vertices[i].Set(sinf(angle), cosf(angle));
        }
        vertices[0].Set( 0, 4 );
        vertices[3].Set( 0, -4 );
        polygonShape.Set(vertices, 6);

        //fixture definition
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &polygonShape;
        myFixtureDef.density = 1;

        //create dynamic body
        myBodyDef.position.Set(0, 10);
        m_body = m_world->CreateBody(&myBodyDef);
        m_body->CreateFixture(&myFixtureDef);

        //zero gravity
        m_world->SetGravity( b2Vec2(0,0) );

        m_rotateMethod = RM_SET_VELOCITY;

        m_clickedPoint = b2Vec2(0,20);//initial starting point
    }

    void MouseDown(const b2Vec2& p)
    {
        m_clickedPoint = p;

        Test::MouseDown( p );//run normal mouse behavior to allow dragging of the body
    }

    void Keyboard(unsigned char key)
    {
        switch (key)
        {
        case 'm': //change rotate method
            {
                int newRM = m_rotateMethod + 1;
                if ( newRM > RM_APPLY_IMPULSE )
                    newRM = RM_SET_VELOCITY;
                m_rotateMethod = (rotateMethod)newRM;
            }
            break;

        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        //find current angle difference from target angle
        float bodyAngle = m_body->GetAngle();
        b2Vec2 toTarget = m_clickedPoint - m_body->GetPosition();
        float desiredAngle = atan2f( -toTarget.x, toTarget.y );

        if ( m_rotateMethod == RM_SET_VELOCITY )
        {
            float totalRotation = desiredAngle - bodyAngle;
            while ( totalRotation < 180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
            while ( totalRotation > 180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
            float change = 1 * DEGTORAD; //allow 1 degree rotation per time step
            float newAngle = bodyAngle + b2Min( change, b2Max(-change, totalRotation));
            m_body->SetTransform( m_body->GetPosition(), newAngle );
            m_body->SetAngularVelocity(0);
        }
        else if ( m_rotateMethod == RM_APPLY_TORQUE )
        {
            //this example will rotate to target immediately
            float nextAngle = bodyAngle + m_body->GetAngularVelocity() / 60.0;
            float totalRotation = desiredAngle - nextAngle;
            while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
            while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
            float desiredAngularVelocity = totalRotation * 60;
            float torque = m_body->GetInertia() * desiredAngularVelocity / (1/60.0);
            m_body->ApplyTorque( torque );
        }
        else if ( m_rotateMethod == RM_APPLY_IMPULSE )
        {
            //this example is limited to rotate 10 degrees per time step
            float nextAngle = bodyAngle + m_body->GetAngularVelocity() / 3.0;
            float totalRotation = desiredAngle - nextAngle;
            while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
            while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
            float desiredAngularVelocity = totalRotation * 60;
            float change = 10 * DEGTORAD; //allow 1 degree rotation per time step
            desiredAngularVelocity = b2Min( change, b2Max(-change, desiredAngularVelocity));
            float impulse = m_body->GetInertia() * desiredAngularVelocity;
            m_body->ApplyAngularImpulse( impulse );
        }

        //show some text on screen
        m_debugDraw.DrawString(5, m_textLine, "Click to set target point");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press m to change rotate method");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Current rotate method: %s", m_rotateMethod == RM_SET_VELOCITY?"SetAngularVelocity":m_rotateMethod==RM_APPLY_TORQUE?"ApplyTorque":"ApplyAngularImpulse");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Body angle %.3f", bodyAngle * RADTODEG);
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Target angle %.3f", desiredAngle * RADTODEG);
        m_textLine += 15;

        //draw the clicked point
        glPointSize(4);
        glBegin(GL_POINTS);
        glVertex2f( m_clickedPoint.x, m_clickedPoint.y );
        glEnd();
    }

    static Test* Create()
    {
        return new iforce2d_rotate_to_angle;
    }

    //class member variables
    rotateMethod m_rotateMethod;
    b2Body* m_body;
    b2Vec2 m_clickedPoint;
};

#endif
