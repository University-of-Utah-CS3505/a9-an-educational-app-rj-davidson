#ifndef IFORCE2D_FORCES_H
#define IFORCE2D_FORCES_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_forces : public Test
{
public:
    iforce2d_forces() {

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

        //create identical bodies in different positions
        for (int i = 0; i < 3; i++) {
            myBodyDef.position.Set(-10+i*10, 20);
            m_bodies[i] = m_world->CreateBody(&myBodyDef);
            m_bodies[i]->CreateFixture(&myFixtureDef);
        }

        //a static 'floor' to drop things on
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 0);
        polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
        m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);

        m_forceOn = false;
        m_torqueOn = false;
        m_gravityOn = true;

        //m_world->SetGravity( b2Vec2(0,0)); //uncomment this to disable gravity
    }

    void Keyboard(unsigned char key)
    {
        switch (key)
        {

        //linear functions
        case 'q':
            m_forceOn = !m_forceOn;
            break;
        case 'w':
            //apply immediate force upwards
            m_bodies[1]->ApplyLinearImpulse( b2Vec2(0,50), m_bodies[1]->GetWorldPoint( b2Vec2(1,1) ) );
            break;
        case 'e':
            //teleport or 'warp' to new location
            m_bodies[2]->SetTransform( b2Vec2(10,20), 0 );
            break;

        //anglular functions
        case 'a':
            m_torqueOn = !m_torqueOn;
            break;
        case 's':
            //apply immediate spin counter clockwise
            m_bodies[1]->ApplyAngularImpulse( 20 );
            break;

        case 'g':
            //gravity toggle
            m_world->SetGravity( b2Vec2(0, m_world->GetGravity().y == 0 ? -10 : 0 ) );
            break;

        default:
            //run default behaviour
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        if (m_forceOn)
            m_bodies[0]->ApplyForce( b2Vec2(0,50), m_bodies[0]->GetWorldPoint( b2Vec2(1,1) ) );
        if (m_torqueOn)
            m_bodies[0]->ApplyTorque( 20 );

        //run the default physics and rendering
        Test::Step(settings);

        //show some text in the main screen
        m_debugDraw.DrawString(5, m_textLine, "Linear keys: q/w/e to ApplyForce, ApplyLinearImpulse, SetTransform");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Anglular keys: a/s to ApplyTorque, ApplyAngularImpulse");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Gravity: g to toggle gravity");
        m_textLine += 15;

    }

    static Test* Create()
    {
        return new iforce2d_forces;
    }

    //class member variables
    b2Body* m_bodies[3];
    bool m_forceOn;
    bool m_torqueOn;
    bool m_gravityOn;

};

#endif
