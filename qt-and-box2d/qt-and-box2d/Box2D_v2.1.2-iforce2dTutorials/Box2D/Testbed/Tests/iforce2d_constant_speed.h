#ifndef IFORCE2D_CONSTANT_SPEED_H
#define IFORCE2D_CONSTANT_SPEED_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_constant_speed : public Test
{
public:   
    //for keeping track of input state
    enum moveState {
        MS_STOP,
        MS_LEFT,
        MS_RIGHT,
    };

    //for allowing user to switch methods at runtime
    enum moveMethod {
        MM_SET_VELOCITY,
        MM_APPLY_FORCE,
        MM_APPLY_IMPULSE,
    };

    iforce2d_constant_speed() {

        //body definition
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;

        //shape definition
        b2PolygonShape polygonShape;
        polygonShape.SetAsBox(1, 1); //a 2x2 rectangle

        //fixture definition
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &polygonShape;
        myFixtureDef.density = 1;

        //create dynamic body
        myBodyDef.position.Set(0, 10);
        m_body = m_world->CreateBody(&myBodyDef);
        m_body->CreateFixture(&myFixtureDef);

        //a static body
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 0);
        polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
        b2Body* staticBody = m_world->CreateBody(&myBodyDef);

        //add four walls to the static body
        polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
        staticBody->CreateFixture(&myFixtureDef);

        m_moveState = MS_STOP;
        m_moveMethod = MM_SET_VELOCITY;
    }

    void Keyboard(unsigned char key)
    {
        switch (key)
        {
        case 'q': //move left
            m_moveState = MS_LEFT;
            break;
        case 'w': //stop
            m_moveState = MS_STOP;
            break;
        case 'e': //move right
            m_moveState = MS_RIGHT;
            break;

        case 'm': //change move method
            {
                int newMM = m_moveMethod + 1;
                if ( newMM > MM_APPLY_IMPULSE )
                    newMM = MM_SET_VELOCITY;
                m_moveMethod = (moveMethod)newMM;
            }
            break;

        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        b2Vec2 vel = m_body->GetLinearVelocity();

        if ( m_moveMethod == MM_SET_VELOCITY )
        {
            switch ( m_moveState )
            {
            case MS_LEFT:  vel.x = b2Max( vel.x - 0.1f, -5.0f ); break;
            case MS_STOP:  vel.x *=  0.98; break;
            case MS_RIGHT: vel.x = b2Min( vel.x + 0.1f,  5.0f ); break;
            }
            m_body->SetLinearVelocity( vel );
        }
        else if ( m_moveMethod == MM_APPLY_FORCE )
        {
            float force = 0;
            switch ( m_moveState )
            {
            case MS_LEFT:  if ( vel.x > -5 ) force = -50;  break;
            case MS_STOP:  force = vel.x * -10; break;
            case MS_RIGHT: if ( vel.x <  5 ) force =  50; break;
            }
            m_body->ApplyForce( b2Vec2(force,0), m_body->GetWorldCenter() );
        }
        else if ( m_moveMethod == MM_APPLY_IMPULSE )
        {
            float desiredVel = 0;
            switch ( m_moveState )
            {
            case MS_LEFT:  desiredVel = b2Max( vel.x - 0.1f, -5.0f ); break;//let speed change gradually
            case MS_STOP:  desiredVel =  vel.x * 0.98; break;//let speed decay gradually
            case MS_RIGHT: desiredVel = b2Min( vel.x + 0.1f,  5.0f ); break;//let speed change gradually
            }
            float velChange = desiredVel - vel.x;
            float impulse = m_body->GetMass() * velChange;
            m_body->ApplyLinearImpulse( b2Vec2(impulse,0), m_body->GetWorldCenter() );
        }

        //run the default physics and rendering
        Test::Step(settings);

        //show some text in the main screen
        m_debugDraw.DrawString(5, m_textLine, "Press q/w/e to move left/stop/right");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press m to change move method");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Current move method: %s", m_moveMethod == MM_SET_VELOCITY?"SetVelocity":m_moveMethod==MM_APPLY_FORCE?"ApplyForce":"ApplyLinearImpulse");
        m_textLine += 15;

    }

    static Test* Create()
    {
        return new iforce2d_constant_speed;
    }

    //class member variables
    b2Body* m_body;
    moveState m_moveState;
    moveMethod m_moveMethod;

};

#endif
