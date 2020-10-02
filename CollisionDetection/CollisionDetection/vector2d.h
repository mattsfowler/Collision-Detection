#pragma once

class vector2d
{
private:

public:
	float x;
	float y;

	vector2d() { x = 0.0f; y = 0.0f; }
	vector2d(float x, float y) { this->x = x; this->y = y; }

	vector2d operator + (vector2d const& obj);
	vector2d operator += (vector2d const& obj);
	vector2d operator * (float const& obj);
	vector2d operator *= (float const& obj);
};

