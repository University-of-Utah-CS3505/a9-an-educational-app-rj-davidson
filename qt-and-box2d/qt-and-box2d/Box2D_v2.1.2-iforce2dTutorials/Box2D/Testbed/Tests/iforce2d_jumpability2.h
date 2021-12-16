#ifndef IFORCE2D_JUMPABILITY2_H
#define IFORCE2D_JUMPABILITY2_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

#include <stdio.h>
#include <set>
using namespace std;

//This is just to avoid conflicting names in other tutorial source files.
#define MyContactListener JUMPABILITY2_MyContactListener

set<b2Fixture*> fixturesUnderfoot;

//contact listener implementation
class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact) {
        //check if fixture A was the foot sensor
        void* fixtureUserData = contact->GetFixtureA()->GetUserData();
        if ( (unsigned long)fixtureUserData == 3 )
            fixturesUnderfoot.insert(contact->GetFixtureB());//A is the foot sensor so B is the ground
        //check if fixture B was the foot sensor
        fixtureUserData = contact->GetFixtureB()->GetUserData();
        if ( (unsigned long)fixtureUserData == 3 )
            fixturesUnderfoot.insert(contact->GetFixtureA());//B is the foot sensor so A is the ground
    }

    void EndContact(b2Contact* contact) {
        //check if fixture A was the foot sensor
        void* fixtureUserData = contact->GetFixtureA()->GetUserData();
        if ( (unsigned long)fixtureUserData == 3 )
            fixturesUnderfoot.erase(contact->GetFixtureB());//A is the foot sensor so B is the ground
        //check if fixture B was the foot sensor
        fixtureUserData = contact->GetFixtureB()->GetUserData();
        if ( (unsigned long)fixtureUserData == 3 )
            fixturesUnderfoot.erase(contact->GetFixtureA());//B is the foot sensor so A is the ground
    }
};


MyContactListener contactListenerInstance4;


class iforce2d_jumpability2 : public Test
{
public:

    //named variables for keeping track of input state
    enum _moveState {
        MS_STOP,
        MS_LEFT,
        MS_RIGHT,
    };

    iforce2d_jumpability2() {

        //player body
        {
            //body definition
            b2BodyDef myBodyDef;
            myBodyDef.type = b2_dynamicBody;
            myBodyDef.fixedRotation = true;

            //shape definition for main fixture
            b2PolygonShape polygonShape;
            polygonShape.SetAsBox(1, 2); //a 2x4 rectangle

            //fixture definition
            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &polygonShape;
            myFixtureDef.density = 1;

            //create dynamic body
            myBodyDef.position.Set(0, 10);
            m_body = m_world->CreateBody(&myBodyDef);

            //add main fixture
            m_body->CreateFixture(&myFixtureDef);

            polygonShape.SetAsBox(0.3, 0.3, b2Vec2(0,-2), 0);
            myFixtureDef.isSensor = true;
            b2Fixture* footSensorFixture = m_body->CreateFixture(&myFixtureDef);
            footSensorFixture->SetUserData((void*)3);
        }

        //ground body and wall fixtures
        {
            //a static body
            b2BodyDef myBodyDef;
            myBodyDef.type = b2_staticBody;
            myBodyDef.position.Set(0, 0);

            //polygon shape
            b2PolygonShape polygonShape;
            polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
            b2Body* staticBody = m_world->CreateBody(&myBodyDef);

            //fixture definition
            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &polygonShape;

            //add four walls to the static body
            polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
            staticBody->CreateFixture(&myFixtureDef);
            polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
            staticBody->CreateFixture(&myFixtureDef);
            polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
            staticBody->CreateFixture(&myFixtureDef);
            polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
            staticBody->CreateFixture(&myFixtureDef);
        }

        //add some dynamic bodies to jump around on
        {
            //body definition
            b2BodyDef myBodyDef;
            myBodyDef.position.Set(-5,5);
            myBodyDef.type = b2_dynamicBody;

            //shape definition
            b2PolygonShape polygonShape;
            polygonShape.SetAsBox(1, 1); //a 2x2 rectangle

            //fixture definition
            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &polygonShape;
            myFixtureDef.density = 1;

            for (int i = 0; i < 5; i++)
            {
                b2Fixture* fixture = m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);
                fixture->SetUserData((void*)1);
            }

            //change size
            polygonShape.SetAsBox(0.5, 1); //a 1x2 rectangle
            for (int i = 0; i < 5; i++)
            {
                b2Fixture* fixture = m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);
                fixture->SetUserData((void*)2);
            }
        }

        //set contact listener in world
        m_world->SetContactListener(&contactListenerInstance4);

        m_moveState = MS_STOP;
        m_remainingJumpSteps = 0;
        m_jumpTimeout = 0;
    }

    bool CanJumpNow()
    {
        if ( m_jumpTimeout > 0 )
            return false;
        set<b2Fixture*>::iterator it = fixturesUnderfoot.begin();
        set<b2Fixture*>::iterator end = fixturesUnderfoot.end();
        while (it != end)
        {
            b2Fixture* fixture = *it;
            int userDataTag = (unsigned long)fixture->GetUserData();
            if ( userDataTag == 0 || userDataTag == 1 )
                return true;
            ++it;
        }
        return false;
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
            if ( !CanJumpNow() ) break;
            //ok to jump
            {
                b2Vec2 vel = m_body->GetLinearVelocity();
                vel.y = 10;//upwards - don\'t change x velocity
                m_body->SetLinearVelocity( vel );
                m_jumpTimeout = 15;
            }
            break;
        case 'k': //jump using force
            if ( !CanJumpNow() ) break;
            //ok to jump
            m_remainingJumpSteps = 6;// 1/10th of a second at 60Hz ( force is applied in Step() )
            m_jumpTimeout = 15;
            break;
        case 'l': //jump using impulse
            if ( !CanJumpNow() ) break;
            {
                //ok to jump
                b2Vec2 jumpImpulse(0, m_body->GetMass() * 10);
                m_body->ApplyLinearImpulse( jumpImpulse, m_body->GetWorldCenter() );
                m_jumpTimeout = 15;

                //kick the underfoot boxes downwards with an equal and opposite impulse
                b2Vec2 locationOfImpulseInPlayerBodyCoords(0, -2);
                b2Vec2 locationOfImpulseInWorldCoords =
                        m_body->GetWorldPoint(locationOfImpulseInPlayerBodyCoords);
                set<b2Fixture*>::iterator it = fixturesUnderfoot.begin();
                set<b2Fixture*>::iterator end = fixturesUnderfoot.end();
                while (it != end)
                {
                    b2Fixture* fixture = *it;
                    fixture->GetBody()->ApplyLinearImpulse( -jumpImpulse, locationOfImpulseInWorldCoords );
                    ++it;
                }
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

        //decrement jump timeout counter
        m_jumpTimeout--;

        //run the default physics and rendering
        Test::Step(settings);
        m_debugDraw.DrawString(5, m_textLine, "Press q/w/e to move left/stop/right");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press j/k/l to jump using SetLinearVelocity/ApplyForce/ApplyLinearImpulse");
        m_textLine += 15;

        m_debugDraw.DrawString(5, m_textLine, "Number of fixtures underfoot: %d", fixturesUnderfoot.size());
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Can I jump here? %s", CanJumpNow()?"yes":"no");
        m_textLine += 15;
    }

    static Test* Create()
    {
        return new iforce2d_jumpability2;
    }

    //class member variables
    b2Body* m_body;
    _moveState m_moveState;
    int m_remainingJumpSteps;
    int m_jumpTimeout;

};

//This is just to avoid conflicting names in other tutorial source files.
#undef MyContactListener
#undef numFootContacts

#endif
