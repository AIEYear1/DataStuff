#include "Vec2.h"
#include <iostream>

Vec2::Vec2()
{
	x = 0;
	y = 0;
}
Vec2::Vec2(float X, float Y)
{
	x = X;
	y = Y;
}
Vec2::Vec2(Vector2 vector)
{
	x = vector.x;
	y = vector.y;
}

float Vec2::Magnitude()
{
	return sqrtf((x * x) + (y * y));
}
float Vec2::Distance(Vec2 vector)
{
	float distX = vector.x - x;
	float distY = vector.y - y;
	return sqrtf((distX * distX) + (distY * distY));
}

void Vec2::Normalize()
{
	if (*this == Vec2())
		return;

	float multiplier = 1 / Magnitude();
	x *= multiplier;
	y *= multiplier;
}
Vec2 Vec2::Normalized()
{
	if (*this == Vec2())
		return *this;

	Vec2 toReturn = *this;
	toReturn.Normalize();
	return toReturn;
}
void Vec2::ClampMagnitude(float magnitude)
{
	if (Magnitude() <= magnitude || *this == Vec2())
		return;

	float x = magnitude / Magnitude();
	*this *= x;
}

float Vec2::Dot(Vec2 vector)
{
	return (x * vector.x) + (y * vector.y);
}
Vec2 Vec2::GetPerpendicular()
{
	return Vec2(y, -x);
}

float Vec2::AngleBetween(Vec2 vector)
{
	float toReturn = acos(Dot(vector) / (Magnitude() * vector.Magnitude()));
	return toReturn * (180 / PI);
}
float Vec2::SignedAngle(Vec2 vector)
{
	return AngleBetween(vector) * ((GetPerpendicular().AngleBetween(vector) > 90) ? -1 : 1);
}

Vec2::operator Vector2()
{
	return Vector2{ x,y };
}
Vec2 Vec2::operator*(float rhs)
{
	return Vec2(x * rhs, y * rhs);
}
Vec2 Vec2::operator/(float rhs)
{
	return Vec2(x / rhs, y / rhs);
}
Vec2 Vec2::operator+(Vec2 rhs)
{
	return Vec2(x + rhs.x, y + rhs.y);
}
Vec2 Vec2::operator-(Vec2 rhs)
{
	return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator*=(float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}
Vec2 Vec2::operator/=(float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}
Vec2 Vec2::operator+=(Vec2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}
Vec2 Vec2::operator-=(Vec2 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vec2 Vec2::operator-()
{
	return Vec2(-x, -y);
}
bool Vec2::operator==(Vec2 rhs)
{
	return (x == rhs.x && y == rhs.y);
}
bool Vec2::operator!=(Vec2 rhs)
{
	return (x != rhs.x || y != rhs.y);
}