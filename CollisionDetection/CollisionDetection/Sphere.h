#pragma once
#include "coreMath.h"
#include <math.h>
#include <limits>
#include <assert.h>
#include <iostream>

class Sphere
{
protected:
	float radius;
	Vector2 totalForce;
	int colour[3];

public:
	Sphere();
	Sphere(const float& radius);

	// In Janusz's solution, these were private but had public getters and setters. Initially I explicitly made them public.
	// Is there an argument for Janusz's method though?
	//  - The application doesn't need access the pointer of the sphere to alter it's values
	//  - More consistent to have all values altered by setters
	//  - Flexibility to change underlying data structure if required
	float inverseMass;
	float dampening;
	Vector2 position;
	Vector2 velocity;

	float getRadius() const { return radius; }
	float getMass() const;
	int getColour(const char& col);
	void setMass(const float &mass);
	void setColour(const int &r, const int &g, const int &b);

	bool isMovable() const;
	void addForce(const Vector2 &force);
	void clearForce();
	void update(const float &duration);
};

