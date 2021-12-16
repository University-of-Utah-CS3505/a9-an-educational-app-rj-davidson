#ifndef FOOTEST_H
#define FOOTEST_H

#include <vector>
#include <set>
#include <typeinfo>
#include <stdio.h>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

class Entity {
public:
    virtual ~Entity() {}
};

class Ball : public Entity {
public:
  //class member variables
  float m_radius;
  b2Vec2 m_position;
  float m_angle;
  b2Vec2 m_linearVelocity;
  bool m_contacting;
  int m_numContacts;
  bool m_imIt;
  b2Body* m_body;
  b2World* m_world;

public:
  Ball(b2World* world, float radius) {
      m_body = NULL;
    m_radius = radius;
    m_world = world;

    //set up dynamic body, store in class variable
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody;
    myBodyDef.position.Set(0, 20);    
    m_body = world->CreateBody(&myBodyDef);
    m_body->SetUserData( this ); //set this Ball object in the body's user data

    //add circle fixture
    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0); 
    circleShape.m_radius = m_radius; //use class variable
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &circleShape;
    myFixtureDef.density = 1;
    myFixtureDef.restitution = 1;
    m_body->CreateFixture(&myFixtureDef);

    m_contacting = false;
    m_numContacts = 0;
    m_imIt = false;
  }
  ~Ball() {
      m_world->DestroyBody(m_body);
  }

  void startContact() { m_numContacts++; }
  void endContact() { m_numContacts--; }

  //in Ball class
  void renderAtBodyPosition() {
    //call normal render at different position/rotation
    glPushMatrix();
    glTranslatef( m_position.x, m_position.y, 0 );
    glRotatef( m_angle * RADTODEG, 0, 0, 1 );
    glScalef( m_radius, m_radius, 1 );
    render();
    glPopMatrix();
  }

  void render() {
    /*float red = m_linearVelocity.Length() / 10.0;
    red = min( 1, red );
    glColor3f(red,0.5,0.5);*/

      if ( m_imIt )
          glColor3f(1,0,0);//red
      else
          glColor3f(1,1,1);//white

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


std::set<Ball*> ballsScheduledForRemoval;

bool outbreak = false;

void handleContact( Ball* b1, Ball* b2 ) {
    if ( ! outbreak )
      return;
    if ( b1->m_imIt ) {
        ballsScheduledForRemoval.insert(b1);
        b2->m_imIt = true;
    }
    else if ( b2->m_imIt ) {
        ballsScheduledForRemoval.insert(b2);
        b1->m_imIt = true;
    }
}

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact) {

        //check if both fixtures were balls
        Entity* bodyAUserData = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
        Entity* bodyBUserData = (Entity*)contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyAUserData && bodyBUserData )
            //printf("%s\n", typeid(*bodyAUserData).name());
            handleContact( static_cast<Ball*>( bodyAUserData ),
                           static_cast<Ball*>( bodyBUserData ) );

      }

  /*void BeginContact(b2Contact* contact) {

    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->startContact();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->startContact();

  }

  void EndContact(b2Contact* contact) {

    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->endContact();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->endContact();

  }*/
};

MyContactListener myContactListenerInstance;

class FooTest : public Test
{

std::vector<Ball*> balls;

public:

  FooTest() {        
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
    for (int i = 0; i < 20; i++) {
      float radius = 1 + 2 * (rand()/(float)RAND_MAX); //random between 1 - 3
      Ball* ball = new Ball(m_world, radius);
      balls.push_back( ball );
    }


//in FooTest constructor
m_world->SetContactListener(&myContactListenerInstance);

balls[0]->m_imIt = true;
m_world->SetGravity( b2Vec2(0,0) );

outbreak = false;

  }

void Keyboard(unsigned char key) { outbreak = true; }

  void Step(Settings* settings)
  {
    //run the default physics and rendering
    Test::Step(settings);

    b2Body* b = m_world->GetBodyList();//get start of list
    while ( b != NULL ) {

      //obtain Ball pointer from user data
      Ball* ball = static_cast<Ball*>( b->GetUserData() );
      if ( ball != NULL ) {
        ball->m_position = b->GetPosition();
        ball->m_angle = b->GetAngle();
        ball->m_linearVelocity = b->GetLinearVelocity();
      }

      //continue to next body
      b = b->GetNext();
    }

    //process list for deletion
    std::set<Ball*>::iterator it = ballsScheduledForRemoval.begin();
    std::set<Ball*>::iterator end = ballsScheduledForRemoval.end();
    for (; it!=end; ++it) {
        Ball* dyingBall = *it;

        //delete ball...
        delete dyingBall;

        //... and remove it from main list of balls
        std::vector<Ball*>::iterator it = std::find(balls.begin(), balls.end(), dyingBall);
        if ( it != balls.end() )
            balls.erase( it );
    }

    //clear this list for next time
    ballsScheduledForRemoval.clear();


    for (int i = 0; i < balls.size(); i++)
      balls[i]->renderAtBodyPosition();

    //show some text in the main screen
    //m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
    //m_textLine += 15;
    
  }

  static Test* Create()
  {
    return new FooTest;
  }

};

#endif
