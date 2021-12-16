#ifndef IFORCE2D_JOINTS_PRISMATIC_H
#define IFORCE2D_JOINTS_PRISMATIC_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_joints_prismatic : public Test
{

public:
    iforce2d_joints_prismatic() {
        //a static body for the 'ground'
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

        //m_world->SetGravity( b2Vec2(0,0) );

        //create the two bodies
        {
            //body and fixture defs - the common parts
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            b2FixtureDef fixtureDef;

            //two boxes
            b2PolygonShape squareShapeA;
            squareShapeA.SetAsBox(5,3);
            b2PolygonShape squareShapeB;
            squareShapeB.SetAsBox(1,4);

            //large box a little to the left
            bodyDef.position.Set(-5, 10);
            fixtureDef.shape = &squareShapeA;
            fixtureDef.density = 2;
            m_bodyA = m_world->CreateBody( &bodyDef );
            m_bodyA->CreateFixture( &fixtureDef );

            //small box a little to the right
            bodyDef.position.Set(5, 10);
            fixtureDef.shape = &squareShapeB;
            fixtureDef.density = 1;
            m_bodyB = m_world->CreateBody( &bodyDef );
            m_bodyB->CreateFixture( &fixtureDef );
        }

        //set up a prismatic joint between chassis and lift slider body
        {
            b2PrismaticJointDef prismaticJointDef;
            prismaticJointDef.bodyA = m_bodyA;
            prismaticJointDef.bodyB = m_bodyB;
            prismaticJointDef.collideConnected = false;

            //local axis, relative to bodyA
            prismaticJointDef.localAxis1.Set(0,1);

            //anchor points
            prismaticJointDef.localAnchorA.Set( 6,-3);//a little outside the bottom right corner
            prismaticJointDef.localAnchorB.Set(-1,-4);//bottom left corner

            prismaticJointDef.referenceAngle = 5 * DEGTORAD;

            //limits
            prismaticJointDef.enableLimit = true;
            prismaticJointDef.lowerTranslation = 0;
            prismaticJointDef.upperTranslation = 10;

            //motor
            prismaticJointDef.enableMotor = true;
            prismaticJointDef.maxMotorForce = 500;
            prismaticJointDef.motorSpeed = 0;

            m_joint1 = (b2PrismaticJoint*)m_world->CreateJoint( &prismaticJointDef );
        }

        //add another body for the lift tray and attach to
        //the lift slider with another prismatic joint
        {
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            b2FixtureDef fixtureDef;
            fixtureDef.density = 1;
            fixtureDef.friction = 0.9f;//default value is too slippery
            b2PolygonShape boxShape;
            fixtureDef.shape = &boxShape;

            //start a close to the lift slider.
            //The joint will correct the position so it doesn't
            //really matter, but starting close to the final position
            //helps to stop things jerking violently in the first
            //few time steps of the simulation
            bodyDef.position.Set( 5, 12);
            b2Body* trayBody = m_world->CreateBody( &bodyDef );

            //this body will have two fixtures
            boxShape.SetAsBox(0.3, 3, b2Vec2(0,3), 0);
            trayBody->CreateFixture( &fixtureDef );
            boxShape.SetAsBox(3, 0.3, b2Vec2(3,0), 0);
            trayBody->CreateFixture( &fixtureDef );

            //set up joint
            b2PrismaticJointDef prismaticJointDef;
            prismaticJointDef.bodyA = m_bodyB;
            prismaticJointDef.bodyB = trayBody;
            prismaticJointDef.collideConnected = true;
            prismaticJointDef.localAxis1.Set(1,0);
            prismaticJointDef.localAnchorA.Set(1,-4);//bottom right corner of lift slider
            prismaticJointDef.localAnchorB.Set(-0.5,-0.5);//bottom left corner of tray
            prismaticJointDef.enableLimit = true;
            prismaticJointDef.lowerTranslation = 0;
            prismaticJointDef.upperTranslation = 7;
            prismaticJointDef.enableMotor = true;//let user toggle this later
            prismaticJointDef.maxMotorForce = 300;
            prismaticJointDef.motorSpeed = -4;

            m_joint2 = (b2PrismaticJoint*)m_world->CreateJoint( &prismaticJointDef );
        }

        //something to play with
        {
            //platforms, attached to already existing 'ground' body
            //maskBits set to 2 so only collides with the cargo box
            b2FixtureDef fixtureDef;
            b2PolygonShape boxShape;
            fixtureDef.shape = &boxShape;
            fixtureDef.filter.maskBits = 2;
            boxShape.SetAsBox(4,0.5, b2Vec2(15,2.75), 0);
            staticBody->CreateFixture(&fixtureDef);
            boxShape.SetAsBox(4,0.5, b2Vec2(15,11), 0);
            staticBody->CreateFixture(&fixtureDef);

            //a box with categoryBits set to 2
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            fixtureDef.density = 1;
            fixtureDef.friction = 0.9f;//default value is too slippery
            fixtureDef.filter.categoryBits = 2;
            fixtureDef.filter.maskBits = 0xFFFF;//restore mask bits to default value
            boxShape.SetAsBox(2,2);
            bodyDef.position.Set(14,4);
            m_world->CreateBody(&bodyDef)->CreateFixture(&fixtureDef);
        }
    }

    void Keyboard(unsigned char key)
    {
        //use keys to change motor direction
        switch (key)
        {
        case 'w':
            m_joint1->SetMotorSpeed( 3 );
            break;
        case 's':
            m_joint1->SetMotorSpeed( -3 );
            break;
        case 'a':
            m_joint2->SetMotorSpeed( -2 );
            break;
        case 'd':
            m_joint2->SetMotorSpeed( 2 );
            break;
        case 'c'://stop both joints. Yeah a little crude, but without a KeyboardUp function it will have to do
            m_joint1->SetMotorSpeed( 0 );
            m_joint2->SetMotorSpeed( 0 );
            break;

        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        m_debugDraw.DrawString(5, m_textLine, "Press w/a/s/d to move the forklift joints");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press c to cancel movement");
        m_textLine += 15;

        m_debugDraw.DrawString(5, m_textLine, "Current joint translation: %.3f", m_joint1->GetJointTranslation());
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Current joint speed: %.3f", m_joint1->GetJointSpeed());
        m_textLine += 15;
    }

    static Test* Create()
    {
        return new iforce2d_joints_prismatic;
    }

    //class member variables
    b2Body* m_bodyA;//main chassis
    b2Body* m_bodyB;//main lift slider (vertically moving piece)
    b2PrismaticJoint* m_joint1;//joint between chassis and main slider body
    b2PrismaticJoint* m_joint2;//joint between main slider and lift tray
};

#endif
