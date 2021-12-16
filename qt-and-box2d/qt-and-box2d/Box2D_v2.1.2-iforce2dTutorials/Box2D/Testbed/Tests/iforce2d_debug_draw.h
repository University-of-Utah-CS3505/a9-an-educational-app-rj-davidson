#ifndef IFORCE2D_DEBUG_DRAW_H
#define IFORCE2D_DEBUG_DRAW_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

//A custom debug draw class using OpenGL ES 1.1 draw functions
//Only DrawSolidPolygon is implemented as an example
class FooDraw : public b2DebugDraw
{
public:
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {}
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {
        //set up vertex array
        GLfloat glverts[16]; //allow for polygons up to 8 vertices
        glVertexPointer(2, GL_FLOAT, 0, glverts); //tell OpenGL where to find vertices
        glEnableClientState(GL_VERTEX_ARRAY); //use vertices in subsequent calls to glDrawArrays

        //fill in vertex positions as directed by Box2D
        for (int i = 0; i < vertexCount; i++) {
            glverts[i*2]   = vertices[i].x;
            glverts[i*2+1] = vertices[i].y;
        }
	
        //draw solid area
        glColor3f( color.r, color.g, color.b );
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);

        //draw lines
        glLineWidth(3); //fat lines
        glColor3f( 1, 0, 1 ); //purple
        glDrawArrays(GL_LINE_LOOP, 0, vertexCount);

        glLineWidth(1);
    }
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {}
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {}
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {}
    void DrawTransform(const b2Transform& xf) {}
};

//declare an instance of the custom debug draw class at global scope to
//use as a callback implementation. This could be a class member, the
//point is that it should not go out of scope while we're using it.
FooDraw fooDrawInstance;

//apart from the last two lines of the constructor, this is
//the same as the 'jumping' topic code
class iforce2d_debug_draw : public Test
{
public:

    //named variables for keeping track of input state
    enum _moveState {
        MS_STOP,
        MS_LEFT,
        MS_RIGHT,
    };

    iforce2d_debug_draw() {
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

        //set custom debug draw for world callback
        fooDrawInstance.SetFlags( b2DebugDraw::e_shapeBit );
        m_world->SetDebugDraw( &fooDrawInstance );
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
        return new iforce2d_debug_draw;
    }

    //class member variables
    b2Body* m_body;
    _moveState m_moveState;
    int m_remainingJumpSteps;

};

#endif
