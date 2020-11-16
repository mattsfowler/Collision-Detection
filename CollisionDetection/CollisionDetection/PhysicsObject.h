#pragma once
#include "coreMath.h"
#include <limits>

class PhysicsObject
{
public:
	virtual void addForce(const Vector2& force) {}
	virtual void nudge(const Vector2& amount) {}
	virtual Vector2 position() const { return Vector2(); }
	virtual Vector2 velocity() const { return Vector2(); }
	virtual float mass() const { return FLT_MAX; }
	virtual bool isMovable() const { return false; }
};