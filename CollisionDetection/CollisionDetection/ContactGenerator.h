#pragma once
#include "PhysicsObject.h"
#include "CirclePhysics.h"
#include "PlatformPhysics.h"
#include "Contact.h"

class ContactGenerator
{
private:
	ContactGenerator() { }

public:
	static Contact generate(CirclePhysics* c1, CirclePhysics* c2);
	static Contact generate(CirclePhysics* c, PlatformPhysics* p);
};

