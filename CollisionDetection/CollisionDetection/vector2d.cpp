#include "vector2d.h"

vector2d vector2d::operator+(vector2d const& obj)
{
	vector2d res = vector2d();
	res.x = x + obj.x;
	res.y = y + obj.y;
	return res;
}

vector2d vector2d::operator+=(vector2d const& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	return *this;
}

vector2d vector2d::operator*(float const& obj)
{
	vector2d res = vector2d();
	res.x = x * obj;
	res.y = y * obj;
	return res;
}

vector2d vector2d::operator*=(float const& obj)
{
	this->x *= obj;
	this->y *= obj;
	return *this;
}
