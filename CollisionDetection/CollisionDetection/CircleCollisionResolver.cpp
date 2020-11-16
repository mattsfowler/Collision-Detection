#include "CircleCollisionResolver.h"
#include <iostream>


void CircleCollisionResolver::resolveAll(Contact* contactArray, unsigned numContacts, unsigned maxIterations, float duration)
{

}

/*
	If duration is 0 or less, no time has elapsed and so no physics needs to be updated.

	Calculate impulse using: 
		kinetic energy = velocity * mass
		momentum = difference of kinetic energy along contact normal
		force = change in momentum per second
		impulse = force / time

	Apply restitution to reduce the actual impulse given to each circle (otherwise it would be an elastic collision)

	The circles overlap (that's how the collision was detected)...
	so nudge each circle in opposite directions along the contact normal.
*/
void CircleCollisionResolver::resolve(Contact* contact, float duration, float restitution)
{
	if (duration <= 0) return;

	Vector2 contactLine = contact->contactNormal;
	float totalMomentum = ((contact->objA->velocity() * contactLine) * contact->objA->mass()) - ((contact->objB->velocity() * contactLine) * contact->objB->mass());

	Vector2 impulse = (contactLine * totalMomentum) * (1.0f / duration);
	Vector2 impulseInv = Vector2(-impulse.x, -impulse.y);

	if (contact->objB->isMovable() == false)
		contact->objA->addForce(impulseInv * restitution * 2.0f);
	else
		contact->objA->addForce(impulseInv * restitution);

	if (contact->objA->isMovable() == false)
		contact->objB->addForce(impulse * restitution * 2.0f);
	else
		contact->objB->addForce(impulse * restitution);
	
	Vector2 overlap = contactLine.unit() * contact->separation * 0.5f;
	contact->objA->nudge(overlap * -1.0f);
	contact->objB->nudge(overlap);
}

