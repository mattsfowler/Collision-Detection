#include "Sphere.h"

void Sphere::addForce(Vector2 force)
{
	PhysicsObject::addForce(force);
}

void Sphere::clearForce()
{
	PhysicsObject::clearForce();
}

void Sphere::update(float duration)
{
	PhysicsObject::update(duration);
}
