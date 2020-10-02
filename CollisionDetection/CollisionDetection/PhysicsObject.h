#pragma once
#include "vector2d.h"
#include <math.h>
#include <limits>
#include <assert.h>
#include <iostream>


class PhysicsObject
{
protected:
	float inverseMass;
	float drag;
	vector2d position;
	vector2d velocity;
	vector2d totalForce;

public:
	float getMass() { return 1.0f / inverseMass; }
	float getDrag() { return drag; }
	vector2d getPosition() { return position; }
	vector2d getVelocity() { return velocity; }
	void setMass(float mass) { assert(mass > 0); this->inverseMass = 1.0f / mass; }
	void setInverseMass(float invMass) { inverseMass = invMass; }
	void setDrag(float drag) { this->drag = drag; }
	void setPosition(vector2d pos) { position = pos; }
	void setVelocity(vector2d vel) { velocity = vel; }
	bool isMovable() { return inverseMass > 0.0f; }
	void addForce(vector2d force) { totalForce = totalForce + force; }
	void clearForce() { totalForce.x = 0.0f; totalForce.y = 0.0f; }
	void update(float duration);
};

