#pragma once

class vector2d
{
private:

public:
	float x;
	float y;

	vector2d() { x = 0.0f; y = 0.0f; }
	vector2d(float x, float y) { this->x = x; this->y = y; }

	vector2d operator + (vector2d const& obj)
	{
		vector2d res = vector2d();
		res.x = x + obj.x;
		res.y = y + obj.y;
		return res;
	}
	vector2d operator += (vector2d const& obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		return *this;
	}
	vector2d operator * (float const& obj)
	{
		vector2d res = vector2d();
		res.x = x * obj;
		res.y = y * obj;
		return res;
	}
	vector2d operator *= (float const& obj)
	{
		this->x *= obj;
		this->y *= obj;
		return *this;
	}

	//vector2d inverse() { return vector2d(-y, -x); }
};

