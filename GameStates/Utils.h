#pragma once
#include "raylib.h"
#include "Timer.h"
#include "Vec2.h"
#define SCREENSPACE CLITERAL(Rectangle){ 0, 0, 1600, 900 }
#define CENTER CLITERAL(Vector2){ SCREENSPACE.width / 2, SCREENSPACE.height / 2 }

float Lerp(float s, float e, float i);
float Abs(float val);
double Abs(double val);

float Min(float val, float min);
float Max(float val, float max);
float Clamp(float val, float min, float max);

float GetAxis(const char *axis);

class cameracenter
{
public:
	static cameracenter &instance();

	operator Vec2();
	void setPos(Vec2 position);
private:
	Vec2 pos;
	cameracenter();
};
