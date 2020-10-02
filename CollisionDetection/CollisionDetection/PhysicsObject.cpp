#include "PhysicsObject.h"

void PhysicsObject::update(float duration)
{
	// if immovable, nothing to update
	if (isMovable() == false) return;

	// F = ma  -->  a = f/m  -->  a = f*(1/m)
	vector2d acceleration = totalForce * inverseMass;
	
	// acceleration = change in velocity
	velocity += acceleration * duration;

	// drag
	velocity *= pow(drag, duration);

	// velocity = change in position
	position += velocity * duration;

	this->clearForce();
}
