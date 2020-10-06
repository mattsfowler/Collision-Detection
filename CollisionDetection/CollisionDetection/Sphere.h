#pragma once
#include "PhysicsObject.h"

class Sphere : public PhysicsObject
{
private:
	float radius;

public:
	Sphere() { radius = 1; }
	Sphere(float radius) { this->radius = radius; }

	void addForce(Vector2 force);
	void clearForce();
	void update(float duration);

	float getRadius() { return radius; }
};

