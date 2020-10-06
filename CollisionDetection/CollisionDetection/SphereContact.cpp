#include "SphereContact.h"

void SphereContact::resolve(float duration)
{
	resolveVelocity(duration);
}

float SphereContact::calculateSeparatingVelocity() const
{
	Vector2 relativeVelocity = sphere[0]->velocity;
	if (sphere[1]) relativeVelocity -= sphere[1]->velocity;
	return relativeVelocity * contactNormal;
}

// developed from Janusz's solution
void SphereContact::resolveVelocity(float duration)
{
	float separatingVelocity = calculateSeparatingVelocity();
	if (separatingVelocity > 0) return;
	float newSepVelocity = -separatingVelocity * restitution;

	// We apply the change in velocity to each object in proportion to
	//  their inverse mass (i.e. those with lower inverse mass [higher actual mass]
	//  get less change in velocity).. 
	float deltaVelocity = newSepVelocity - separatingVelocity;

	float totalInverseMass = sphere[0]->inverseMass;
	if (sphere[1]) totalInverseMass += sphere[1]->inverseMass;

	// If all particles have infinite mass, then impulses have no effect 
	if (totalInverseMass <= 0) return;

	// Calculate the impulse to apply 
	float impulse = deltaVelocity / totalInverseMass;

	// Find the amount of impulse per unit of inverse mass
	// Apply impulses: they are applied in the direction of the contact,
	// and are proportional to the inverse mass.
	Vector2 impulsePerIMass = contactNormal * impulse;
	sphere[0]->velocity += (impulsePerIMass * sphere[0]->inverseMass);
	if (sphere[1]) sphere[1]->velocity += (impulsePerIMass * sphere[1]->inverseMass);
}
