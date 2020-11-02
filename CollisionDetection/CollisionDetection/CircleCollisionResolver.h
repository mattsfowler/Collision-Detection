#pragma once
#include "CirclePhysics.h"
#include "coreMath.h"
#include <algorithm>

class CircleCollisionResolver
{
private:
	CircleCollisionResolver() {}

public:
	static bool isCollision(const CirclePhysics& s1, const CirclePhysics& s2);
	static void resolve(CirclePhysics* s1, CirclePhysics* s2, float duration);
	static void resolve(CirclePhysics* s1, CirclePhysics* s2, float duration, float restitution);
};

