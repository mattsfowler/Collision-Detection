#pragma once
#include "vector2d.h"
#include <math.h>
#include <limits>
#include <assert.h>
#include <iostream>


class PhysicsObject
{
protected:
	vector2d totalForce;

public:
	float inverseMass;
	float dampening;
	vector2d position;
	vector2d velocity;
	
	float getMass();
	void setMass(float mass);
	bool isMovable();
	void addForce(vector2d force);
	void clearForce();
	void update(float duration);
};

