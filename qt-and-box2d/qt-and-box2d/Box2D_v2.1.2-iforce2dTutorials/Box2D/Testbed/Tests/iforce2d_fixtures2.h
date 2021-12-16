#ifndef IFORCE2D_FIXTURES2_H
#define IFORCE2D_FIXTURES2_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

//demonstrates fixture properties

class iforce2d_fixtures2 : public Test
{
public:
    iforce2d_fixtures2() {

        //create a dynamic body
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(14, 10);
        b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);

        //prepare a fixture def
        b2PolygonShape polygonShape;
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &polygonShape;
        myFixtureDef.density = 1;
        myFixtureDef.friction = 1;

        //add four square shaped fixtures around the body center
        for ( int i = 0; i < 4; i++) {
            b2Vec2 pos( sinf(i*90*DEGTORAD), cosf(i*90*DEGTORAD) );
            polygonShape.SetAsBox(1, 1, pos, 0 ); //a 2x2 rectangle
            myFixtureDef.restitution = i/4.0;//different restitution for each fixture
            myFixtureDef.friction = i/4.0;//different friction for each fixture
            dynamicBody->CreateFixture(&myFixtureDef); //add a fixture to the body
        }

        //a static 'floor' to drop things on
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 0); //middle, bottom
        b2Body* staticBody = m_world->CreateBody(&myBodyDef);
        polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,3) ); //slightly sloped
        myFixtureDef.friction = 0.9f;//floor will not be slippery
        myFixtureDef.restitution = 0;//floor will not be bouncy
        staticBody->CreateFixture(&myFixtureDef); //add a fixture to the body

    }

    static Test* Create()
    {
        return new iforce2d_fixtures2;
    }

};

#endif
