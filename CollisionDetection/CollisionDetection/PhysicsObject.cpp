#include "PhysicsObject.h"

float PhysicsObject::getMass()
{
	if (inverseMass == 0) return FLT_MAX;
	else return 1.0f / inverseMass;
}

void PhysicsObject::setMass(float mass)
{
	assert(mass > 0);
	inverseMass = 1.0f / mass;
}

bool PhysicsObject::isMovable()
{
	return inverseMass > 0.0f;
}

void PhysicsObject::addForce(Vector2 force)
{
	totalForce += force;
}

void PhysicsObject::clearForce()
{
	totalForce.x = 0.0f; 
	totalForce.y = 0.0f;
}

void PhysicsObject::update(float duration)
{
	// if immovable, nothing to update
	if (isMovable() == false) return;

	// F = ma  -->  a = f/m  -->  a = f*(1/m)
	Vector2 acceleration = totalForce * inverseMass;
	
	// acceleration = change in velocity
	velocity += acceleration * duration;

	// dampening, primitive drag simulation
	velocity *= pow(dampening, duration);

	// velocity = change in position
	position += velocity * duration;

	this->clearForce();
}
