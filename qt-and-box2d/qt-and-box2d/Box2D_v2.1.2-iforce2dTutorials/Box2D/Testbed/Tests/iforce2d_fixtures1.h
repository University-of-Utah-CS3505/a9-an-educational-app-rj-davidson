#ifndef IFORCE2D_FIXTURES1_H
#define IFORCE2D_FIXTURES1_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

//demonstrates the creation of different fixture types, and multiple fixtures on one body

class iforce2d_fixtures1 : public Test
{
public:
    iforce2d_fixtures1() {        

        //a dynamic body to attach fixtures to
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(-10, 20);
        b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);

        //a circle shape for the first fixture
        b2CircleShape circleShape;
        circleShape.m_p.Set(0, 0); //position, relative to body position
        circleShape.m_radius = 1; //radius

        //this fixture def can be reused for all fixtures, just change the necessary settings before calling CreateFixture
        b2FixtureDef myFixtureDef;
        myFixtureDef.density = 1;//must be non-zero to allow rotation
        myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
        dynamicBody->CreateFixture(&myFixtureDef);

        //At this point we have one circle fixture attached to the body, at (0,0) in body
        //coords, and the body's position is at (-10,20). It is important to note that
        //the body's origin is at the circle center. Aince we will be adding the other
        //fixtures at offset locations, we need to place them away from the body origin:

        //create a polygon shape manually for the second fixture
        b2PolygonShape polygonShape;
        b2Vec2 vertices[5];
        vertices[0].Set(-1 +10,  2);//+10 here to move everything 10 units right
        vertices[1].Set(-1 +10,  0);
        vertices[2].Set( 0 +10, -3);
        vertices[3].Set( 1 +10,  0);
        vertices[4].Set( 1 +10,  1);
        polygonShape.Set(vertices, 5);

        myFixtureDef.shape = &polygonShape; //change fixture def to use different shape
        dynamicBody->CreateFixture(&myFixtureDef);

        //change shape to a standard rectangle
        polygonShape.SetAsBox(2, 1, b2Vec2(20,0), 0 ); //a 4x2 rectangle, 20 units to the right of the body origin (the circle)
        dynamicBody->CreateFixture(&myFixtureDef); //add a fixture to the body

        //static body for the ground
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0,0); //middle, bottom of screen

        //change shape to an edge
        polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) ); //ends of the line
        b2Body* staticBody = m_world->CreateBody(&myBodyDef);
        staticBody->CreateFixture(&myFixtureDef);

    }

    static Test* Create()
    {
        return new iforce2d_fixtures1;
    }

};

#endif
