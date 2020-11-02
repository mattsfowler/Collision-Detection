#pragma once
#include "coreMath.h"
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
	float dampening;
	int colour[3];
};


class CirclePhysics
{
private:
	Circle sphere;
	float pixelsPerMetre;

public:
	CirclePhysics(Circle initialState);
	CirclePhysics();
	void update(const float& duration);
	void addForce(const Vector2& force);
	void clearForce();
	void resolveBorder(const int& width, const int& height);
	void resolveOverlap(const CirclePhysics& s);

	bool isMovable() const;
	float inverseMass() const;
	float mass() const;
	float radius() const;
	Vector2 position() const;
	Vector2 velocity() const;
	int colour(const char& col);
};

