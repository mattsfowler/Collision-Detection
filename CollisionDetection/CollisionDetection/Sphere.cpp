#include "Sphere.h"

Sphere::Sphere()
{
	Sphere::Sphere(1.0f);
}

Sphere::Sphere(const float& radius)
{
	this->radius = radius;
	this->dampening = 1.0f;
	this->inverseMass = 0.0f;
	this->setColour(0, 0, 0);
}

float Sphere::getMass() const
{
	if (inverseMass == 0) return FLT_MAX;
	else return 1.0f / inverseMass;
}

int Sphere::getColour(const char& col)
{
	if (col == 'r' || col == 'R') 
		return this->colour[0];
	if (col == 'g' || col == 'G')
		return this->colour[1];
	if (col == 'b' || col == 'B')
		return this->colour[2];
	return 0;
}

void Sphere::setMass(const float &mass)
{
	assert(mass > 0);
	inverseMass = 1.0f / mass;
}

void Sphere::setColour(const int& r, const int& g, const int& b)
{
	this->colour[0] = r;
	this->colour[1] = g;
	this->colour[2] = b;
}

bool Sphere::isMovable() const
{
	return inverseMass > 0.0f;
}

void Sphere::addForce(const Vector2 &force)
{
	totalForce += force;
}

void Sphere::clearForce()
{
	totalForce.x = 0.0f;
	totalForce.y = 0.0f;
}

void Sphere::update(const float &duration)
{
	// if immovable, nothing to update
	if (isMovable() == false) return;

	// F = ma  -->  a = f/m  -->  a = f*(1/m)
	Vector2 acceleration = Vector2(0.0f, 0.0f);
	acceleration.addScaledVector(totalForce, inverseMass);

	// acceleration = change in velocity
	velocity.addScaledVector(acceleration, duration);

	// dampening, primitive drag simulation
	velocity *= powf(dampening, duration);

	// velocity = change in position
	position += velocity;

	this->clearForce();
}
