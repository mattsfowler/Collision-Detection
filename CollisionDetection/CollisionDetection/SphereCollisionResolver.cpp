#include "SphereCollisionResolver.h"
#include <iostream>


bool SphereCollisionResolver::isCollision(const SphereGeometry& s1, const SphereGeometry& s2)
{
	float separation = sqrtf(powf(s2.position().x - s1.position().x, 2.0f) + powf(s2.position().y - s1.position().y, 2.0f));
	float sumRadii = s1.radius() + s2.radius();

	if (separation < sumRadii)
		return true;
	else
		return false;
}

void SphereCollisionResolver::resolve(SphereGeometry* s1, SphereGeometry* s2, float duration)
{
	resolve(s1, s2, duration, 1.0f);
}

void SphereCollisionResolver::resolve(SphereGeometry* s1, SphereGeometry* s2, float duration, float restitution)
{
	if (duration <= 0) return;

	Vector2 contactLine = ( s1->position() - s2->position() ).unit();
	float totalMomentum = ((s1->velocity() * contactLine) * s1->mass()) - ((s2->velocity() * contactLine) * s2->mass());

	Vector2 impulse1 = (contactLine * totalMomentum) * (1.0f / duration);
	Vector2 impulse2 = Vector2(-impulse1.x, -impulse1.y);

	s1->addForce(impulse2 * restitution);
	s2->addForce(impulse1 * restitution);

	s1->resolveOverlap(*s2);
	s2->resolveOverlap(*s1);
}

