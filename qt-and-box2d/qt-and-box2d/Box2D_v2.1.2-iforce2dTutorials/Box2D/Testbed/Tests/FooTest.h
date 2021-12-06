#ifndef FOOTEST_H
#define FOOTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class FooTest : public Test
{
public:
  FooTest() {
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(0, 20); //set the starting position
    myBodyDef.angle = 0; //set the starting angle

    //dynamicBody = m_world->CreateBody(&myBodyDef);

    float physScale = 12;

    b2PolygonShape boxShape;
    boxShape.SetAsBox(6/physScale,6/physScale);
  
    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    boxFixtureDef.restitution = 0.25;
    boxFixtureDef.friction = 0;

    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 50; ++i) {
            myBodyDef.position.Set((20 + j * 14) / physScale, (20 + i * 14) / physScale);
            m_world->CreateBody(&myBodyDef)->CreateFixture(&boxFixtureDef);
        }
    }

    m_world->SetGravity(b2Vec2(0,0));

    b2CircleShape circleShape;
    circleShape.m_radius = 10 / physScale;
    boxFixtureDef.density = 10.0;
    boxFixtureDef.restitution = 1.0;
    boxFixtureDef.friction = 0.0;
    boxFixtureDef.shape = &circleShape;
    myBodyDef.position.Set(-250, 400 / physScale);
    myBodyDef.bullet = true;
    dynamicBody = m_world->CreateBody(&myBodyDef);
    dynamicBody->CreateFixture(&boxFixtureDef);

    dynamicBody->ApplyLinearImpulse(b2Vec2(80000, 0), myBodyDef.position);

  }

  void Step(Settings* settings)
  {
    //run the default physics and rendering
    Test::Step(settings);

    //show some information for the dynamic body
    b2Vec2 pos = dynamicBody->GetPosition();
    float angle = dynamicBody->GetAngle();
    b2Vec2 vel = dynamicBody->GetLinearVelocity();
    float angularVel = dynamicBody->GetAngularVelocity();
    m_debugDraw.DrawString(5, m_textLine,
                           "Velocity:%.3f,%.3f", vel.x, vel.y, angle * RADTODEG);
    m_textLine += 15;
    
  }

  //return an object of this class to the testbed
  static Test* Create()
  {
    return new FooTest;
  }

  b2Body* dynamicBody;
  b2Body* staticBody;
  b2Body* kinematicBody;
};

#endif

