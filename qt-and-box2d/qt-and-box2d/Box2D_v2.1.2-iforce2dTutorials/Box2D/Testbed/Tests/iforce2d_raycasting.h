#ifndef IFORCE2D_RAYCASTING_H
#define IFORCE2D_RAYCASTING_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

float currentRayAngle = 0;

class iforce2d_raycasting : public Test
{
public:
    iforce2d_raycasting() {

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

        m_drawRecursive = false;

    }

    void drawSingleRay( b2Vec2 p1, b2Vec2 p2 )
    {
        //set up input
        b2RayCastInput input;
        input.p1 = p1;
        input.p2 = p2;
        input.maxFraction = 1;

        //check every fixture of every body to find closest
        float closestFraction = 1; //start with end of line as p2
        b2Vec2 intersectionNormal(0,0);
        for (b2Body* b = m_world->GetBodyList(); b; b = b->GetNext()) {
            for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {

                b2RayCastOutput output;
                if ( ! f->RayCast( &output, input ) )
                    continue;
                if ( output.fraction < closestFraction ) {
                    closestFraction = output.fraction;
                    intersectionNormal = output.normal;
                }
            }
        }

        b2Vec2 intersectionPoint = p1 + closestFraction * (p2 - p1);

        //draw a line
        glColor3f(1,1,1); //white
        glBegin(GL_LINES);
        glVertex2f( p1.x, p1.y );
        glVertex2f( intersectionPoint.x, intersectionPoint.y );
        glEnd();

        //draw a point at the intersection point
        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2f( intersectionPoint.x, intersectionPoint.y );
        glEnd();

        //draw intersection normal
        b2Vec2 normalEnd = intersectionPoint + intersectionNormal;
        glColor3f(0,1,0); //green
        glBegin(GL_LINES);
        glVertex2f( intersectionPoint.x, intersectionPoint.y );
        glVertex2f( normalEnd.x, normalEnd.y );
        glEnd();
    }

    void drawRecursiveRay( b2Vec2 p1, b2Vec2 p2 )
    {
        //set up input
        b2RayCastInput input;
        input.p1 = p1;
        input.p2 = p2;
        input.maxFraction = 1;

        //check every fixture of every body to find closest
        float closestFraction = 1; //start with end of line as p2
        b2Vec2 intersectionNormal(0,0);
        for (b2Body* b = m_world->GetBodyList(); b; b = b->GetNext()) {
            for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext()) {

                b2RayCastOutput output;
                if ( ! f->RayCast( &output, input ) )
                    continue;
                if ( output.fraction < closestFraction ) {
                    closestFraction = output.fraction;
                    intersectionNormal = output.normal;
                }
            }
        }
        b2Vec2 intersectionPoint = p1 + closestFraction * (p2 - p1);

        //draw this part of the ray
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2f( p1.x, p1.y );
        glVertex2f( intersectionPoint.x, intersectionPoint.y );
        glEnd();

        if ( closestFraction == 1 )
            return; //ray hit nothing so we can finish here
        if ( closestFraction == 0 ) //this happens when the ray intersects an edge shape - to avoid infinite recursion we need to stop here
            return;

        //still some ray left to reflect
        b2Vec2 remainingRay = (p2 - intersectionPoint);
        b2Vec2 projectedOntoNormal = b2Dot(remainingRay, intersectionNormal) * intersectionNormal;
        b2Vec2 nextp2 = p2 - 2 * projectedOntoNormal;

        //recurse
        drawRecursiveRay(intersectionPoint, nextp2);
    }

    void Keyboard(unsigned char key)
    {
        switch (key)
        {
        case 'm':
            m_drawRecursive = !m_drawRecursive;
            break;

        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        currentRayAngle += 360 / 20.0 / 60.0 * DEGTORAD; //one revolution every 20 seconds

        float rayLength = 25; //long enough to hit the walls, but not reach the corners
        b2Vec2 p1( 0, 20 ); //center of scene
        b2Vec2 p2 = p1 + rayLength * b2Vec2( sinf(currentRayAngle), cosf(currentRayAngle) );

        if ( m_drawRecursive )
            drawRecursiveRay(p1, p2);
        else
            drawSingleRay(p1, p2);

        m_debugDraw.DrawString(5, m_textLine, "Press m to change ray type");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Current type: %s", m_drawRecursive?"recursive":"single");
        m_textLine += 15;
    }

    static Test* Create()
    {
        return new iforce2d_raycasting;
    }

    bool m_drawRecursive;

};

#endif
