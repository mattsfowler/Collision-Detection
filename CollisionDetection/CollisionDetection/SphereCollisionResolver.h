#pragma once
#include "SphereGeometry.h"
#include "coreMath.h"
#include <algorithm>

class SphereCollisionResolver
{
private:
	SphereCollisionResolver() {}

public:
	static bool isCollision(const SphereGeometry& s1, const SphereGeometry& s2);
	static void resolve(SphereGeometry* s1, SphereGeometry* s2, float duration);
	static void resolve(SphereGeometry* s1, SphereGeometry* s2, float duration, float restitution);
};

