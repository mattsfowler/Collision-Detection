#include "CirclePhysics.h"

CirclePhysics::CirclePhysics(Circle initialState)
{
	if (initialState.mass == 0)
		initialState.mass = FLT_MAX;
	this->circle = initialState;
	this->pixelsPerMetre = 20.0f;
}

CirclePhysics::CirclePhysics()
{
	CirclePhysics(Circle());
}

void CirclePhysics::update(const float& duration)
{
	if (isMovable() == false)
		return;

	Vector2 acceleration = Vector2(0.0f, 0.0f);
	acceleration.addScaledVector(circle.totalForce, inverseMass());

	circle.velocity.addScaledVector(acceleration, duration);

	circle.position.addScaledVector(circle.velocity, duration * pixelsPerMetre);
	this->clearForce();
}

void CirclePhysics::addForce(const Vector2& force)
{
	circle.totalForce += force;
}

void CirclePhysics::clearForce()
{
	circle.totalForce.x = 0.0f;
	circle.totalForce.y = 0.0f;
}

void CirclePhysics::resolveBorder(const int& width, const int& height)
{
	if (circle.position.x > width - circle.radius)
	{
		circle.velocity.x = -circle.velocity.x;
		circle.position.x = width - circle.radius;
	}
	if (circle.position.x < -width + circle.radius)
	{
		circle.velocity.x = -circle.velocity.x;
		circle.position.x = -width + circle.radius;
	}
	if (circle.position.y > height - circle.radius)
	{
		circle.velocity.y = -circle.velocity.y;
		circle.position.y = height - circle.radius;
	}
	if (circle.position.y < -height + circle.radius)
	{
		circle.velocity.y = -circle.velocity.y;
		circle.position.y = -height + circle.radius;
	}
}

void CirclePhysics::nudge(const Vector2& amount)
{
	this->circle.position += amount;
}

bool CirclePhysics::isMovable() const
{
	return circle.mass != FLT_MAX;
}

float CirclePhysics::inverseMass() const
{
	return 1.0f / circle.mass;
}

float CirclePhysics::mass() const
{
	return circle.mass;
}

float CirclePhysics::radius() const
{
	return circle.radius;
}

Vector2 CirclePhysics::position() const
{
	return circle.position;
}

Vector2 CirclePhysics::velocity() const
{
	return circle.velocity;
}

int CirclePhysics::colour(const char& col)
{
	if (col == 'r' || col == 'R')
		return circle.colour[0];
	if (col == 'g' || col == 'G')
		return circle.colour[1];
	if (col == 'b' || col == 'B')
		return circle.colour[2];
	return 0;
}
