#pragma once
#include "coreMath.h"
#include "PhysicsObject.h"

#include <math.h>
#include <limits>
#include <assert.h>
#include <iostream>
#include <algorithm>


struct Circle
{
	float radius;
	float mass;
	Vector2 position;
	Vector2 velocity;
	Vector2 totalForce;
	int colour[3];
};


class CirclePhysics : public PhysicsObject
{
private:
	Circle circle;
	float pixelsPerMetre;

public:
	CirclePhysics(Circle initialState);
	CirclePhysics(); // is this needed?
	void update(const float& duration);
	void addForce(const Vector2& force);
	void clearForce();
	void resolveBorder(const int& width, const int& height);
	void nudge(const Vector2& amount);

	bool isMovable() const;
	float inverseMass() const;
	float mass() const;
	float radius() const;
	Vector2 position() const;
	Vector2 velocity() const;
	int colour(const char& col);
};

