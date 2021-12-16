#ifndef IFORCE2D_JOINTS_REVOLUTE_H
#define IFORCE2D_JOINTS_REVOLUTE_H

#ifndef DEGTORAD
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#endif

class iforce2d_joints_revolute : public Test
{

public:
    iforce2d_joints_revolute() {
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
		fixtureDef.density = 1;

		//two shapes
		b2PolygonShape boxShape;
		boxShape.SetAsBox(2,2);
		b2CircleShape circleShape;
		circleShape.m_radius = 2;	

		//make box a little to the left
		bodyDef.position.Set(-13, 10);
		fixtureDef.shape = &boxShape;
		m_bodyA = m_world->CreateBody( &bodyDef );
		m_bodyA->CreateFixture( &fixtureDef );

		//and circle a little to the right
		bodyDef.position.Set( -7, 10);
		fixtureDef.shape = &circleShape;
		m_bodyB = m_world->CreateBody( &bodyDef );
		m_bodyB->CreateFixture( &fixtureDef );
	}

	//set up a revolute joint
	{
		b2RevoluteJointDef revoluteJointDef;
		revoluteJointDef.bodyA = m_bodyA;
		revoluteJointDef.bodyB = m_bodyB;
		revoluteJointDef.collideConnected = false;
		
		//anchor points
		revoluteJointDef.localAnchorA.Set(2,2);//the top right corner of the box
		revoluteJointDef.localAnchorB.Set(0,0);//center of the circle

		//limits
		revoluteJointDef.enableLimit = true;
		revoluteJointDef.lowerAngle = -45 * DEGTORAD;
		revoluteJointDef.upperAngle =  45 * DEGTORAD;

		//motor
		revoluteJointDef.enableMotor = false;//let user toggle this later
		revoluteJointDef.maxMotorTorque = 50;
		revoluteJointDef.motorSpeed = 90 * DEGTORAD;//90 degrees per second

		m_joint = (b2RevoluteJoint*)m_world->CreateJoint( &revoluteJointDef );
	}

	//make a chain
	{
		//body and fixture defs are common to all chain links
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(5,10);
		b2FixtureDef fixtureDef;
		fixtureDef.density = 1;
		b2PolygonShape polygonShape;
		polygonShape.SetAsBox(1,0.25);
		fixtureDef.shape = &polygonShape;

		//set up the common properties of the joint before entering the loop
		b2RevoluteJointDef revoluteJointDef;
		revoluteJointDef.localAnchorA.Set( 0.75,0);
		revoluteJointDef.localAnchorB.Set(-0.75,0);

		b2Body* link = m_world->CreateBody( &bodyDef );
		link->CreateFixture( &fixtureDef );

		for (int i = 0; i < 10; i++) {
			b2Body* newLink = m_world->CreateBody( &bodyDef );
			newLink->CreateFixture( &fixtureDef );

			//inside the loop, only need to change the bodies
			revoluteJointDef.bodyA = link;
			revoluteJointDef.bodyB = newLink;
			m_world->CreateJoint( &revoluteJointDef );

			link = newLink;//prepare for next iteration
		}

		//body with circle fixture
		b2CircleShape circleShape;
		circleShape.m_radius = 2;
		fixtureDef.shape = &circleShape;
		b2Body* chainBase = m_world->CreateBody( &bodyDef );
		chainBase->CreateFixture( &fixtureDef );

		//a revolute joint to connect the circle to the ground
		revoluteJointDef.bodyA = m_groundBody;//provided by testbed
		revoluteJointDef.bodyB = chainBase;
		revoluteJointDef.localAnchorA.Set(4,20);//world coords, because m_groundBody is at (0,0)
		revoluteJointDef.localAnchorB.Set(0,0);//center of circle
		m_world->CreateJoint( &revoluteJointDef );

		//another revolute joint to connect the chain to the circle
		revoluteJointDef.bodyA = link;//the last added link of the chain
		revoluteJointDef.bodyB = chainBase;
		revoluteJointDef.localAnchorA.Set(0.75,0);//the regular position for chain link joints, as above
		revoluteJointDef.localAnchorB.Set(1.75,0);//a little in from the edge of the circle
		m_world->CreateJoint( &revoluteJointDef );
	}

        //demonstrate how joints can sometimes not be constrained sufficiently
        /*{
            //body and fixture defs - the common parts
            b2BodyDef bodyDef;
            bodyDef.type = b2_dynamicBody;
            b2FixtureDef fixtureDef;

            //two shapes
            b2PolygonShape boxShape;
            boxShape.SetAsBox(2,2);
            b2CircleShape circleShape;
            circleShape.m_radius = 2;

            //very light circle
            bodyDef.position.Set(10, 8);
            fixtureDef.shape = &circleShape;
            fixtureDef.density = 0.1;
            b2Body* bodyB = m_world->CreateBody( &bodyDef );
            bodyB->CreateFixture( &fixtureDef );

            //very heavy box, fixed rotation
            bodyDef.position.Set(10, 10);
            bodyDef.fixedRotation = true;
            fixtureDef.shape = &boxShape;
            fixtureDef.density = 50;
            b2Body* bodyA = m_world->CreateBody( &bodyDef );
            bodyA->CreateFixture( &fixtureDef );

            //freely rotating joint
            b2RevoluteJointDef revoluteJointDef;
            revoluteJointDef.bodyA = bodyA;
            revoluteJointDef.bodyB = bodyB;
            revoluteJointDef.localAnchorA.Set(0,-2);//middle bottom of the box
            revoluteJointDef.localAnchorB.Set(0,0);//center of the circle

            m_world->CreateJoint( &revoluteJointDef );
        }*/

    }

    void Keyboard(unsigned char key)
    {
        switch (key)
        {
	case 'l': //toggle limits on/off
            m_joint->EnableLimit( ! m_joint->IsLimitEnabled() ); 
            break;
	case 'm': //toggle motor on/off
            m_joint->EnableMotor( ! m_joint->IsMotorEnabled() ); 
            break;

	case 'q':
            m_joint->SetMotorSpeed( 90 * DEGTORAD );
            break;
	case 'w':
	    m_joint->SetMotorSpeed( 0 );
            break;
	case 'e':
            m_joint->SetMotorSpeed( -90 * DEGTORAD );
            break;

        default:
            Test::Keyboard(key);
        }
    }

    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);

        m_debugDraw.DrawString(5, m_textLine, "Press l to toggle limits, m to toggle joint motor");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Press q/w/e to set joint motor direction to ccw/stop/cw");
        m_textLine += 15;

        m_debugDraw.DrawString(5, m_textLine, "Current joint angle: %.3f deg", m_joint->GetJointAngle() * RADTODEG);
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Current joint speed: %.3f deg/s", m_joint->GetJointSpeed() * RADTODEG);
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Joint limits %s", m_joint->IsLimitEnabled() ? "enabled" : "disabled");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Joint motor %s", m_joint->IsMotorEnabled() ? "enabled" : "disabled");
        m_textLine += 15;
        m_debugDraw.DrawString(5, m_textLine, "Joint motor speed: %.3f deg/s", m_joint->GetMotorSpeed() * RADTODEG);
        m_textLine += 15;

    }

    static Test* Create()
    {
        return new iforce2d_joints_revolute;
    }

    //class member variables
    b2Body* m_bodyA;
    b2Body* m_bodyB;
    b2RevoluteJoint* m_joint;

};

#endif
