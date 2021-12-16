#ifndef IFORCE2D_JUMPING_H
#define IFORCE2D_JUMPING_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_jumping : public Test
{
public:

    //named variables for keeping track of input state
    enum _moveState {
        MS_STOP,
        MS_LEFT,
        MS_RIGHT,
    };

    iforce2d_jumping() {
        //body definition
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.fixedRotation = true;

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

        //another box to play with
        m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);

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
        m_remainingJumpSteps = 0;
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

        case 'j': //jump using SetLinearVelocity
            {
                b2Vec2 vel = m_body->GetLinearVelocity();
                vel.y = 10;//upwards - don\'t change x velocity
                m_body->SetLinearVelocity( vel );
            }
            break;
        case 'k': //jump using ApplyForce
            m_remainingJumpSteps = 6;// 1/10th of a second at 60Hz ( force is applied in Step() )
            break;
        case 'l': //jump using ApplyImpulse
            {
                //to change velocity by 10 in one timestep
                float impulse = m_body->GetMass() * 10;
                m_body->ApplyLinearImpulse( b2Vec2(0,impulse), m_body->GetWorldCenter() );
            }
            break;
        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        //simple move body sideways, don't change y component
        b2Vec2 vel = m_body->GetLinearVelocity();
        switch ( m_moveState )
        {
        case MS_LEFT:  vel.x = b2Max( vel.x - 0.1f, -5.0f ); break;
        case MS_STOP:  vel.x *=  0.98; break;
        case MS_RIGHT: vel.x = b2Min( vel.x + 0.1f,  5.0f ); break;
        }
        m_body->SetLinearVelocity( vel );

        //jump using force for a few timesteps
        if ( m_remainingJumpSteps > 0 ) {
            //to change velocity by 10 in one time step, like an impulse
            float force = m_body->GetMass() * 10 / (1/60.0); //f = mv/t
            //but we want to spread this over 6 time steps
            force /= 6.0f;
            m_body->ApplyForce( b2Vec2(0,force), m_body->GetWorldCenter() );
            m_remainingJumpSteps--;
        }

        //run the default physics and rendering
        Test::Step(settings);
        m_debugDraw.DrawString(5, m_textLine, "Press q/w/e to move left/stop/right");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press j/k/l to jump using SetLinearVelocity/ApplyForce/ApplyLinearImpulse");
        m_textLine += 15;
    }

    static Test* Create()
    {
        return new iforce2d_jumping;
    }

    //class member variables
    b2Body* m_body;
    _moveState m_moveState;
    int m_remainingJumpSteps;

};

#endif
