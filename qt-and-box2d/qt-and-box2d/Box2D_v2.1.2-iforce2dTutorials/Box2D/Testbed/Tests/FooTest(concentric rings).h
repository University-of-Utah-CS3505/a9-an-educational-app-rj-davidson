#ifndef FOOTEST_H
#define FOOTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class FooTest : public Test
{
b2Body* dBod;
void Keyboard(unsigned char key)
{
  switch (key)
  {
    case 'q':
      dBod->SetAngularVelocity(1);
      break;
    default:
      //run default behaviour
      Test::Keyboard(key);
  }
}

public:
  FooTest() {
    b2BodyDef myBodyDef;
    myBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    myBodyDef.position.Set(0, 20); //set the starting position
    myBodyDef.angle = 0; //set the starting angle

    b2PolygonShape polygonShape;
  
    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &polygonShape;
    boxFixtureDef.density = 1;
boxFixtureDef.friction = 0.8f;

m_world->SetGravity(b2Vec2(0,0));

/*float radius = 5;
int segments = 16;
for (int r = 0; r < 4; r++) {
    b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
if (r == 0 )dBod = dynamicBody;
	float circum = 2 * M_PI * radius;
	float segmentLength = circum / (float)segments;
	for (int i = 0; i < segments; i++) {
		float angle = i / (float)segments * 360 * DEGTORAD;
		polygonShape.SetAsBox( 0.5f, 0.5f*segmentLength, 
			b2Vec2(radius*sinf(angle), radius*cosf(angle)), 
			-angle+90*DEGTORAD );
		dynamicBody->CreateFixture(&boxFixtureDef);
	}
	radius += 4;
	float nextCircum = 2 * M_PI * radius;
	segments *= nextCircum / circum;
}*/

myBodyDef.type = b2_kinematicBody;
b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);
polygonShape.SetAsBox( 1,1, b2Vec2(3,0), 0);
		dynamicBody->CreateFixture(&boxFixtureDef);
polygonShape.SetAsBox( 1,1, b2Vec2(0,0), 0);
//boxFixtureDef.isSensor = true;
		//dynamicBody->CreateFixture(&boxFixtureDef);
dBod = dynamicBody;


/*
    myBodyDef.type = b2_staticBody;
    myBodyDef.position.Set(0, 0);
    polygonShape.SetAsEdge( b2Vec2(-100,0), b2Vec2(100,0) );
    b2Body* staticBody = m_world->CreateBody(&myBodyDef); //add body to world
    staticBody->CreateFixture(&boxFixtureDef);*/
  
    //kinematicBody->SetLinearVelocity( b2Vec2( 1, 0 ) ); //move right 1 unit per second
    //kinematicBody->SetAngularVelocity( 360 * DEGTORAD ); //1 turn per second counter-clockwise
  } 

  void Step(Settings* settings)
  {
	//dBod->ApplyTorque(1500);

    b2Vec2 pos = dBod->GetPosition();
    float angle = dBod->GetAngle();
    m_debugDraw.DrawString(5, m_textLine, 
			   "Position:%.3f,%.3f Angle:%.3f", pos.x, pos.y, angle * RADTODEG);
    m_textLine += 15;

    //run the default physics and rendering
    Test::Step(settings);
    
  }

  //return an object of this class to the testbed
  static Test* Create()
  {
    return new FooTest;
  }
};

#endif

