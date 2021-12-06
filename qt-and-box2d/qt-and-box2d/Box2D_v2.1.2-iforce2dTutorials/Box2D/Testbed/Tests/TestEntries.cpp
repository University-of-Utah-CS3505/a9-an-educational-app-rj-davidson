/*
* Copyright (c) 2006-2009 Erin Catto http://www.gphysics.com
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#include "../Framework/Test.h"
#include "../Framework/Render.h"
#include "../../freeglut/GL/glut.h"
#include <cstring>

#include "ApplyForce.h"
#include "BodyTypes.h"
#include "Breakable.h"
#include "Bridge.h"
#include "Cantilever.h"
#include "ContinuousTest.h"
#include "Chain.h"
#include "CharacterCollision.h"
#include "CollisionFiltering.h"
#include "CollisionProcessing.h"
#include "CompoundShapes.h"
#include "Confined.h"
#include "DistanceTest.h"
#include "Dominos.h"
#include "DynamicTreeTest.h"
#include "EdgeShapes.h"
#include "Gears.h"
#include "LineJoint.h"
#include "OneSidedPlatform.h"
#include "PolyCollision.h"
#include "PolyShapes.h"
#include "Prismatic.h"
#include "Pulleys.h"
#include "Pyramid.h"
#include "RayCast.h"
#include "Revolute.h"
#include "SensorTest.h"
#include "ShapeEditing.h"
#include "SliderCrank.h"
#include "SphereStack.h"
#include "TheoJansen.h"
#include "TimeOfImpact.h"
#include "VaryingFriction.h"
#include "VaryingRestitution.h"
#include "VerticalStack.h"
#include "Web.h"

//iforce2d tutorials
#include "iforce2d_bodies.h"
#include "iforce2d_fixtures1.h"
#include "iforce2d_fixtures2.h"
#include "iforce2d_forces.h"
#include "iforce2d_constant_speed.h"
#include "iforce2d_rotate_to_angle.h"
#include "iforce2d_jumping.h"
#include "iforce2d_debug_draw.h"
#include "iforce2d_drawing_objects.h"
#include "iforce2d_collision_anatomy.h"
#include "iforce2d_collision_callbacks1.h"
#include "iforce2d_collision_callbacks2.h"
#include "iforce2d_collision_filtering.h"
#include "iforce2d_sensors.h"
#include "iforce2d_raycasting.h"
#include "iforce2d_world_querying.h"
#include "iforce2d_jumpability1.h"
#include "iforce2d_jumpability2.h"
#include "iforce2d_joints_revolute.h"
#include "iforce2d_joints_prismatic.h"

TestEntry g_testEntries[] =
{
        {"Time of Impact", TimeOfImpact::Create},
	{"Ray-Cast", RayCast::Create},
	{"One-Sided Platform", OneSidedPlatform::Create},
	{"Confined", Confined::Create},
	{"Vertical Stack", VerticalStack::Create},
	{"Pyramid", Pyramid::Create},
	{"Varying Restitution", VaryingRestitution::Create},
	{"Theo Jansen's Walker", TheoJansen::Create},
	{"Body Types", BodyTypes::Create},
	{"Character Collision", CharacterCollision::Create},
	{"Prismatic", Prismatic::Create},
	{"Edge Shapes", EdgeShapes::Create},
	{"Continuous Test", ContinuousTest::Create},
	{"PolyCollision", PolyCollision::Create},
	{"Polygon Shapes", PolyShapes::Create},
	{"Apply Force", ApplyForce::Create},
	{"Cantilever", Cantilever::Create},
	{"SphereStack", SphereStack::Create},
	{"Bridge", Bridge::Create},
	{"Breakable", Breakable::Create},
	{"Chain", Chain::Create},
	{"Collision Filtering", CollisionFiltering::Create},
	{"Collision Processing", CollisionProcessing::Create},
	{"Compound Shapes", CompoundShapes::Create},
	{"Distance Test", DistanceTest::Create},
	{"Dominos", Dominos::Create},
	{"Dynamic Tree", DynamicTreeTest::Create},
	{"Gears", Gears::Create},
	{"Line Joint", LineJoint::Create},
	{"Pulleys", Pulleys::Create},
	{"Revolute", Revolute::Create},
	{"Sensor Test", SensorTest::Create},
	{"Shape Editing", ShapeEditing::Create},
	{"Slider Crank", SliderCrank::Create},
	{"Varying Friction", VaryingFriction::Create},
	{"Web", Web::Create},
	{NULL, NULL}
};

TestEntry g_iforce2dEntries[] =
{
        {"Bodies",                  iforce2d_bodies::Create},
        {"Fixtures 1",              iforce2d_fixtures1::Create},
        {"Fixtures 2",              iforce2d_fixtures2::Create},
        {"Forces",                  iforce2d_forces::Create},
        {"Constant speed",          iforce2d_constant_speed::Create},
        {"Rotate to angle",         iforce2d_rotate_to_angle::Create},
        {"Jumping",                 iforce2d_jumping::Create},
        {"Debug draw",              iforce2d_debug_draw::Create},
        {"Drawing objects",         iforce2d_drawing_objects::Create},
        {"Collision anatomy",       iforce2d_collision_anatomy::Create},
        {"Collision callbacks 1",   iforce2d_collision_callbacks1::Create},
        {"Collision callbacks 2",   iforce2d_collision_callbacks2::Create},
        {"Collision filtering",     iforce2d_collision_filtering::Create},
        {"Sensors",                 iforce2d_sensors::Create},
        {"Raycasting",              iforce2d_raycasting::Create},
        {"World querying",          iforce2d_world_querying::Create},
        {"Can I jump? 1",           iforce2d_jumpability1::Create},
        {"Can I jump? 2",           iforce2d_jumpability2::Create},
        {"Joints - revolute",       iforce2d_joints_revolute::Create},
        {"Joints - prismatic",      iforce2d_joints_prismatic::Create},

	{NULL, NULL}
};

TestEntryCategory g_testEntryCategories[] =
{
	{"iforce2d tutorials", g_iforce2dEntries},
	{"Tests", g_testEntries},
	{NULL, NULL}
};


