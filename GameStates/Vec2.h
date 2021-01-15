#pragma once
#include "raylib.h"

struct Vec2
{
	float x = 0;
	float y = 0;

	Vec2();
	Vec2(float X, float Y);
	Vec2(Vector2 vector);

	float Magnitude();
	float Distance(Vec2 vector);

	void Normalize();
	Vec2 Normalized();
	void ClampMagnitude(float magnitude);

	float Dot(Vec2 vector);
	Vec2 GetPerpendicular();

	/// <summary>
	/// finds the angle between two Vectors
	/// </summary>
	float AngleBetween(Vec2 vector);
	float SignedAngle(Vec2 vector);

	operator Vector2();
	Vec2 operator* (float rhs);
	Vec2 operator/ (float rhs);
	Vec2 operator+ (Vec2 rhs);
	Vec2 operator- (Vec2 rhs);

	Vec2 operator*= (float rhs);
	Vec2 operator/= (float rhs);
	Vec2 operator+= (Vec2 rhs);
	Vec2 operator-= (Vec2 rhs);

	Vec2 operator- ();
	bool operator==(Vec2 rhs);
	bool operator!=(Vec2 rhs);
};

