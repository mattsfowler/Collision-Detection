#pragma once
#include "Sphere.h"
#include "coreMath.h"

class SphereContact
{
public:
	Sphere* sphere[2];
	float restitution;
	Vector2 contactNormal;
	float penetration;

protected:
	void resolve(float duration);
	float calculateSeparatingVelocity() const;

private:
	void resolveVelocity(float duration);
};