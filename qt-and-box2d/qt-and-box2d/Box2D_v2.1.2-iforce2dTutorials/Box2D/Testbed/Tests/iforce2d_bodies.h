#ifndef IFORCE2D_BODIES_H
#define IFORCE2D_BODIES_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

//demonstrates characteristics of dynamic, static and kinematic bodies

class iforce2d_bodies : public Test
{
public:
    iforce2d_bodies() {
        //shape to use for all bodies
        b2PolygonShape boxShape;
        boxShape.SetAsBox(1,1);

        //fixture to use for all bodies
        b2FixtureDef boxFixtureDef;
        boxFixtureDef.shape = &boxShape;
        boxFixtureDef.density = 1;

        //body def can be reused, just change settings as necessary before calling CreateBody
        b2BodyDef myBodyDef;

        //dynamic body
        myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
        myBodyDef.position.Set(0, 20); //set the starting position
        myBodyDef.angle = 0; //set the starting angle
        m_dynamicBody = m_world->CreateBody(&myBodyDef);
        m_dynamicBody->CreateFixture(&boxFixtureDef);
        m_dynamicBody->SetTransform( b2Vec2( 10, 20 ), 45 * DEGTORAD ); //45 degrees counter-clockwise
        m_dynamicBody->SetLinearVelocity( b2Vec2( -5, 5 ) ); //moving up and left 5 units per second
        m_dynamicBody->SetAngularVelocity( -90 * DEGTORAD ); //90 degrees per second clockwise

        //static body
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 10); //slightly lower position
        m_staticBody = m_world->CreateBody(&myBodyDef); //add body to world
        m_staticBody->CreateFixture(&boxFixtureDef); //add fixture to body

        //kinematic body
        myBodyDef.type = b2_kinematicBody;
        myBodyDef.position.Set(-8, 11); // start from left side, slightly above the static body
        m_kinematicBody = m_world->CreateBody(&myBodyDef); //add body to world
        m_kinematicBody->CreateFixture(&boxFixtureDef); //add fixture to body
        m_kinematicBody->SetLinearVelocity( b2Vec2( 1, 0 ) ); //move right 1 unit per second
        m_kinematicBody->SetAngularVelocity( 360 * DEGTORAD ); //1 turn per second counter-clockwise
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        //show some information for the dynamic body
        b2Vec2 pos = m_dynamicBody->GetPosition();
        float angle = m_dynamicBody->GetAngle();
        b2Vec2 vel = m_dynamicBody->GetLinearVelocity();
        float angularVel = m_dynamicBody->GetAngularVelocity();
        m_debugDraw.DrawString(5, m_textLine, "Position:%.3f,%.3f Angle:%.3f", pos.x, pos.y, angle * RADTODEG);
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Velocity:%.3f,%.3f Angular velocity:%.3f", vel.x, vel.y, angularVel * RADTODEG);
        m_textLine += 15;

    }

    //return an object of this class to the testbed
    static Test* Create()
    {
        return new iforce2d_bodies;
    }

    //stored references to the bodies
    b2Body* m_dynamicBody;
    b2Body* m_staticBody;
    b2Body* m_kinematicBody;
};

#endif

