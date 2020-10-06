#pragma once
#include "coreMath.h"
#include <math.h>
#include <limits>
#include <assert.h>
#include <iostream>


class PhysicsObject
{
protected:
	Vector2 totalForce;

public:
	float inverseMass;
	float dampening;
	Vector2 position;
	Vector2 velocity;
	
	float getMass();
	void setMass(float mass);
	bool isMovable();
	virtual void addForce(Vector2 force);
	virtual void clearForce();
	virtual void update(float duration);
};

