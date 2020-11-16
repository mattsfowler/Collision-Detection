#include "ContactGenerator.h"


Contact ContactGenerator::generate(CirclePhysics* c1, CirclePhysics* c2)
{
	float distBetweenCentres = sqrtf(powf(c2->position().x - c1->position().x, 2.0f) + powf(c2->position().y - c1->position().y, 2.0f));
	float sumRadii = c1->radius() + c2->radius();

	Contact contact = Contact();
	contact.objA = c1;
	contact.objB = c2;
	contact.contactNormal = (c1->position() - c2->position()).unit();
	contact.separation = distBetweenCentres - sumRadii;
	return contact;
}


Contact ContactGenerator::generate(CirclePhysics* c, PlatformPhysics* p)
{
	Contact contact = Contact();
	contact.objA = c;
	contact.objB = p;

	Vector2 platformToCircle = c->position() - p->start();
	Vector2 lineDirection = p->end() - p->start();
	float projected = platformToCircle * lineDirection; //how far along the platform is the circle?

	if (projected <= 0) // circle closest to start of the line
	{
		// nothing to do
	}
	else if (projected >= lineDirection.squareMagnitude()) // circle closest to end of the line
	{
		platformToCircle = c->position() - p->end();
	}
	else // circle in the middle of the line
	{
		Vector2 closestPoint = p->start() + lineDirection * (projected / lineDirection.squareMagnitude());
		platformToCircle = c->position() - closestPoint;
	}

	contact.contactNormal = platformToCircle.unit();
	contact.separation = platformToCircle.magnitude() - c->radius();
	return contact;
}
