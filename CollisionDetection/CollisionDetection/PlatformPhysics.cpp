#include "PlatformPhysics.h"

PlatformPhysics::PlatformPhysics()
{
	PlatformPhysics(Platform());
}

PlatformPhysics::PlatformPhysics(Platform initialState)
{
	this->platform = initialState;
	this->pixelsPerMetre = 20.0f;
}

Vector2 PlatformPhysics::start() const
{
	return platform.start;
}

Vector2 PlatformPhysics::end() const
{
	return platform.end;
}

int PlatformPhysics::colour(const char& col)
{
	if (col == 'r' || col == 'R')
		return platform.colour[0];
	if (col == 'g' || col == 'G')
		return platform.colour[1];
	if (col == 'b' || col == 'B')
		return platform.colour[2];
	return 0;
}

bool PlatformPhysics::isMovable() const
{
	return false;
}
