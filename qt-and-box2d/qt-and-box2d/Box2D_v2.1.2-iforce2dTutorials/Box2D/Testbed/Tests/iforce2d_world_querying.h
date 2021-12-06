#ifndef IFORCE2D_WORLD_QUERYING_H
#define IFORCE2D_WORLD_QUERYING_H

#include <vector>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

//subclass b2QueryCallback
class MyQueryCallback : public b2QueryCallback {
public:
    std::vector<b2Body*> foundBodies;

    bool ReportFixture(b2Fixture* fixture) {
        foundBodies.push_back( fixture->GetBody() );
        return true;//keep going to find all fixtures in the query area
    }
};

#include <Box2D/Box2D.h>

class iforce2d_world_querying : public Test
{
public:
    iforce2d_world_querying() {

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
        b2Vec2 bl(-20, 0);
        b2Vec2 br( 20, 0);
        b2Vec2 tl(-20,40);
        b2Vec2 tr( 20,40);
        polygonShape.SetAsEdge( bl, br ); //ground
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsEdge( tl, tr);//ceiling
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsEdge( bl, tl );//left wall
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsEdge( br, tr );//right wall
        staticBody->CreateFixture(&myFixtureDef);

        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(0,20);
        polygonShape.SetAsBox(2,2);
        myFixtureDef.density = 1;
        for (int i = 0; i < 5; i++)
            m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);

        //circles
        b2CircleShape circleShape;
        circleShape.m_radius = 2;
        myFixtureDef.shape = &circleShape;
        for (int i = 0; i < 5; i++)
            m_world->CreateBody(&myBodyDef)->CreateFixture(&myFixtureDef);

        //turn gravity off
        m_world->SetGravity( b2Vec2(0,0) );

    }

    b2Vec2 mouseDownPos, mouseUpPos;

    void MouseDown(const b2Vec2& p) {
        mouseDownPos = mouseUpPos = p;
        //Test::MouseDown(p); //uncomment this if you want to move the bodies around
    }

    void MouseUp(const b2Vec2& p) {
        mouseUpPos = p;
        //Test::MouseUp(p); //uncomment this if you want to move the bodies around
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        //draw the rectangle
        b2Vec2 lower( min(mouseDownPos.x,mouseUpPos.x), min(mouseDownPos.y,mouseUpPos.y) );
        b2Vec2 upper( max(mouseDownPos.x,mouseUpPos.x), max(mouseDownPos.y,mouseUpPos.y) );

        glColor3f(1,1,1);//white
        glBegin(GL_LINE_LOOP);
        glVertex2f(lower.x, lower.y);
        glVertex2f(upper.x, lower.y);
        glVertex2f(upper.x, upper.y);
        glVertex2f(lower.x, upper.y);
        glEnd();

        MyQueryCallback queryCallback;
        b2AABB aabb;
        aabb.lowerBound = lower;
        aabb.upperBound = upper;
        m_world->QueryAABB( &queryCallback, aabb );

        //draw a point on each body in the query area
        glPointSize(6);
        glBegin(GL_POINTS);
        for (int i = 0; i < queryCallback.foundBodies.size(); i++) {
            b2Vec2 pos = queryCallback.foundBodies[i]->GetPosition();
            glVertex2f( pos.x, pos.y );
        }
        glEnd();

        //show some text in the main screen
        m_debugDraw.DrawString(5, m_textLine, "Drag a box to detect fixtures AABBs in an area");
        m_textLine += 15;

    }

    static Test* Create()
    {
        return new iforce2d_world_querying;
    }

};

#endif
