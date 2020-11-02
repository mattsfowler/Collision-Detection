#include "CirclePhysics.h"

CirclePhysics::CirclePhysics(Circle initialState)
{
	if (initialState.mass == 0)
		initialState.mass = FLT_MAX;
	this->sphere = initialState;
	this->pixelsPerMetre = 60.0f;
}

CirclePhysics::CirclePhysics()
{
	CirclePhysics(Sphere());
}

void CirclePhysics::update(const float& duration)
{
	if (isMovable() == false) 
		return;

	Vector2 acceleration = Vector2(0.0f, 0.0f);
	acceleration.addScaledVector(sphere.totalForce, inverseMass());

	sphere.velocity.addScaledVector(acceleration, duration);
	sphere.velocity *= powf(sphere.dampening, duration);

	sphere.position.addScaledVector(sphere.velocity, duration * pixelsPerMetre);
	this->clearForce();
}

void CirclePhysics::addForce(const Vector2& force)
{
	sphere.totalForce += force;
}

void CirclePhysics::clearForce()
{
	sphere.totalForce.x = 0.0f;
	sphere.totalForce.y = 0.0f;
}

void CirclePhysics::resolveBorder(const int& width, const int& height)
{
	if (sphere.position.x > width - sphere.radius)
	{
		sphere.velocity.x = -sphere.velocity.x;
		sphere.position.x = width - sphere.radius;
	}
	if (sphere.position.x < -width + sphere.radius)
	{
		sphere.velocity.x = -sphere.velocity.x;
		sphere.position.x = -width + sphere.radius;
	}
	if (sphere.position.y > height - sphere.radius)
	{
		sphere.velocity.y = -sphere.velocity.y;
		sphere.position.y = height - sphere.radius;
	}
	if (sphere.position.y < -height + sphere.radius)
	{
		sphere.velocity.y = -sphere.velocity.y;
		sphere.position.y = -height + sphere.radius;
	}
}

void CirclePhysics::resolveOverlap(const CirclePhysics& s)
{
	Vector2 contactLine = sphere.position - s.position();
	float separation = (sphere.position - s.position()).magnitude();
	float overlap = std::max(0.0f, -separation + sphere.radius + s.radius());
	sphere.position.addScaledVector(contactLine.unit(), overlap * 0.5f);
}

bool CirclePhysics::isMovable() const
{
	return inverseMass() > 0.0f;
}

float CirclePhysics::inverseMass() const
{
	return 1.0f / sphere.mass;
}

float CirclePhysics::mass() const
{
	return sphere.mass;
}

float CirclePhysics::radius() const
{
	return sphere.radius;
}

Vector2 CirclePhysics::position() const
{
	return sphere.position;
}

Vector2 CirclePhysics::velocity() const
{
	return sphere.velocity;
}

int CirclePhysics::colour(const char& col)
{
	if (col == 'r' || col == 'R')
		return sphere.colour[0];
	if (col == 'g' || col == 'G')
		return sphere.colour[1];
	if (col == 'b' || col == 'B')
		return sphere.colour[2];
	return 0;
}
