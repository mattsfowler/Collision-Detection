#pragma once
#include "coreMath.h"
#include "PhysicsObject.h"


class Contact
{
public:
	PhysicsObject* objA;
	PhysicsObject* objB;
	Vector2 contactNormal;
	float separation;
};