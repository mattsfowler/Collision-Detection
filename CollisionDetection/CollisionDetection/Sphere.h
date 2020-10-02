#pragma once
#include "PhysicsObject.h"

class Sphere : public PhysicsObject
{
private:
	float radius;

public:
	Sphere() { radius = 1; }
	Sphere(float radius) { this->radius = radius; }
	float getRadius() { return radius; }
};

