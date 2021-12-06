#ifndef IFORCE2D_SENSORS_H
#define IFORCE2D_SENSORS_H

#include <vector>

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

#define Ball SENSORS_Ball
#define entityCategory SENSORS_entityCategory
#define MyContactListener SENSORS_MyContactListener

enum entityCategory {
    _BOUNDARY =          0x0001,
    _FRIENDLY_SHIP =     0x0002,
    _ENEMY_SHIP =        0x0004,
    _FRIENDLY_AIRCRAFT = 0x0008,
    _ENEMY_AIRCRAFT =    0x0010,
    _FRIENDLY_TOWER =    0x0020,
    _RADAR_SENSOR =      0x0040,
};

class Ball {
public:
    b2Body* m_body;
protected:
    //class member variables
    float m_radius;
    b2Color m_color;

public:
    Ball(b2World* world, float radius, b2Color color, uint16 categoryBits, uint16 maskBits) {
        m_color = color;
        m_body = NULL;
        m_radius = radius;

        //set up dynamic body, store in class variable
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(0, 20);
        m_body = world->CreateBody(&myBodyDef);
        m_body->SetAngularDamping(1);
        m_body->SetLinearDamping(1);

        //add circle fixture
        b2CircleShape circleShape;
        circleShape.m_p.Set(0, 0);
        circleShape.m_radius = m_radius; //use class variable
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &circleShape;
        myFixtureDef.density = 1;
        myFixtureDef.filter.categoryBits = categoryBits;
        myFixtureDef.filter.maskBits = maskBits;
        m_body->CreateFixture(&myFixtureDef);

        m_body->SetUserData( this );
    }
    ~Ball() {}

    //Ball class member
    std::vector<Ball*> visibleEnemies;

    //in Ball class
    void radarAcquiredEnemy(Ball* enemy) {
        visibleEnemies.push_back( enemy );
    }
    void radarLostEnemy(Ball* enemy) {
        visibleEnemies.erase( std::find(visibleEnemies.begin(), visibleEnemies.end(), enemy ) );
    }

    //in Ball class
    void renderAtBodyPosition() {
        //safety check
        if ( m_body == NULL ) return;

        //get current position from Box2D

        b2Vec2 pos = m_body->GetPosition(); //(existing code)
        glColor3f(1,1,1);//white
        glLineStipple( 1, 0xF0F0 );
        glEnable(GL_LINE_STIPPLE);
        glBegin(GL_LINES);
        for (int i = 0; i < visibleEnemies.size(); i++) {
            b2Vec2 enemyPosition = visibleEnemies[i]->m_body->GetPosition();
            glVertex2f(pos.x, pos.y);
            glVertex2f(enemyPosition.x, enemyPosition.y);
        }
        glEnd();
        glDisable(GL_LINE_STIPPLE);


        float angle = m_body->GetAngle();

        //call normal render at different position/rotation
        glPushMatrix();
        glTranslatef( pos.x, pos.y, 0 );
        glRotatef( angle * RADTODEG, 0, 0, 1 );
        glScalef( m_radius, m_radius, 1 );
        render();
        glPopMatrix();


    }

    void render() {
        /*b2Vec2 vel = m_body->GetLinearVelocity();
    float red = vel.Length() / 10.0;
    red = b2Min( 1, red );
    glColor3f(red,0.5,0.5);*/

        //in Ball::render
        if ( visibleEnemies.size() > 0 )
            glColor3f(1,1,0);
        else
            glColor3f(m_color.r, m_color.g, m_color.b);

        //nose and eyes
        glPointSize(4);
        glBegin(GL_POINTS);
        glVertex2f( 0, 0 );
        glVertex2f(-0.5, 0.5 );
        glVertex2f( 0.5, 0.5 );
        glEnd();

        //mouth
        glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5,  -0.5 );
        glVertex2f(-0.16, -0.6 );
        glVertex2f( 0.16, -0.6 );
        glVertex2f( 0.5,  -0.5 );
        glEnd();

        //circle
        glBegin(GL_LINE_LOOP);
        for (float a = 0; a < 360 * DEGTORAD; a += 30 * DEGTORAD)
            glVertex2f( sinf(a), cosf(a) );
        glEnd();
    }
};

//helper function to figure out if the collision was between
//a radar and an aircraft, and sort out which is which
bool getRadarAndAircraft(b2Contact* contact, Ball*& radarEntity, Ball*& aircraftEntity)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    //make sure only one of the fixtures was a sensor
    bool sensorA = fixtureA->IsSensor();
    bool sensorB = fixtureB->IsSensor();
    if ( ! (sensorA ^ sensorB) )
        return false;

    Ball* entityA = static_cast<Ball*>( fixtureA->GetBody()->GetUserData() );
    Ball* entityB = static_cast<Ball*>( fixtureB->GetBody()->GetUserData() );

    if ( sensorA ) { //fixtureB must be an enemy aircraft
        radarEntity = entityA;
        aircraftEntity = entityB;
    }
    else { //fixtureA must be an enemy aircraft
        radarEntity = entityB;
        aircraftEntity = entityA;
    }
    return true;
}

//collision call back function, pass to m_world->SetContactListener
class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact) {
        Ball* radarEntity;
        Ball* aircraftEntity;
        if ( getRadarAndAircraft(contact, radarEntity, aircraftEntity) )
            radarEntity->radarAcquiredEnemy( aircraftEntity );
    }

    void EndContact(b2Contact* contact) {
        Ball* radarEntity;
        Ball* aircraftEntity;
        if ( getRadarAndAircraft(contact, radarEntity, aircraftEntity) )
            radarEntity->radarLostEnemy( aircraftEntity );
    }
};

MyContactListener myContactListenerInstance;


class iforce2d_sensors : public Test
{

    std::vector<Ball*> balls;

public:

    iforce2d_sensors() {
        //a static body
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 0);
        b2Body* staticBody = m_world->CreateBody(&myBodyDef);

        //shape definition
        b2PolygonShape polygonShape;

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


        //add ball entity to scene

        b2Color red(1,0,0);
        b2Color green(0,1,0);

        //large and green are friendly ships
        Ball* ship = new Ball(m_world, 3, green, _FRIENDLY_SHIP, _BOUNDARY | _FRIENDLY_TOWER );
        balls.push_back( ship );

        //small and red are enemy aircraft
        for (int i = 0; i < 3; i++)
            balls.push_back( new Ball(m_world, 1, red, _ENEMY_AIRCRAFT, _BOUNDARY | _RADAR_SENSOR ) );

        //a tower entity
        Ball* tower = new Ball(m_world, 1, green, _FRIENDLY_TOWER, _FRIENDLY_SHIP );
        tower->m_body->SetType(b2_kinematicBody);
        balls.push_back( tower );

        //add radar sensor to ship
        b2CircleShape circleShape;
        circleShape.m_radius = 8;
        myFixtureDef.shape = &circleShape;
        myFixtureDef.isSensor = true;
        myFixtureDef.filter.categoryBits = _RADAR_SENSOR;
        myFixtureDef.filter.maskBits = _ENEMY_AIRCRAFT;
        ship->m_body->CreateFixture(&myFixtureDef);

        //add semicircle radar sensor to tower
        float radius = 8;
        b2Vec2 vertices[8];
        vertices[0].Set(0,0);
        for (int i = 0; i < 7; i++) {
            float angle = i / 6.0 * 90 * DEGTORAD;
            vertices[i+1].Set( radius * cosf(angle), radius * sinf(angle) );
        }
        polygonShape.Set(vertices, 8);
        myFixtureDef.shape = &polygonShape;
        tower->m_body->CreateFixture(&myFixtureDef);

        //make the tower rotate at 45 degrees per second
        tower->m_body->SetAngularVelocity(45 * DEGTORAD);

        //balls.erase( std::find(balls.begin(),balls.end(),tower) );
        //balls.erase( std::remove( balls.begin(), balls.end(), tower ), balls.end() );

        /*//large and red are enemy ships
for (int i = 0; i < 3; i++)
  balls.push_back( new Ball(m_world, 3, red, ENEMY_SHIP, BOUNDARY | FRIENDLY_SHIP | ENEMY_SHIP ) );
//small and green are friendly aircraft
for (int i = 0; i < 3; i++)
  balls.push_back( new Ball(m_world, 1, green, FRIENDLY_AIRCRAFT, BOUNDARY | ENEMY_AIRCRAFT ) );*/

        m_world->SetGravity(b2Vec2(0,0));
        m_world->SetContactListener(&myContactListenerInstance);

    }



    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        for (int i = 0; i < balls.size(); i++)
            balls[i]->renderAtBodyPosition();

        //show some text in the main screen
        //m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
        //m_textLine += 15;

    }

    static Test* Create()
    {
        return new iforce2d_sensors;
    }

};

#undef Ball
#undef entityCategory
#undef MyContactListener

#endif
