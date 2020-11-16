#pragma once
#include "CirclePhysics.h"
#include "Contact.h"
#include "coreMath.h"
#include <algorithm>

class CircleCollisionResolver
{
private:
	CircleCollisionResolver() {}

public:
	static void resolveAll(Contact* contactArray, unsigned numContacts, unsigned maxIterations, float duration);
	static void resolve(Contact* contact, float duration, float restitution);
};

