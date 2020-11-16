#pragma once
#include "coreMath.h"
#include "PhysicsObject.h"

struct Platform
{
	Vector2 start;
	Vector2 end;
	int colour[3];
};


class PlatformPhysics : public PhysicsObject
{
private:
	Platform platform;
	float pixelsPerMetre;

public:
	PlatformPhysics();
	PlatformPhysics(Platform initialState);

	Vector2 start() const;
	Vector2 end() const;
	int colour(const char& col);
	bool isMovable() const;
};