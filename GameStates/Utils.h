#pragma once
#include "raylib.h"
#include "Timer.h"
#include "cameracenter.h"
#include "Vec2.h"
#include "string.h"
#define SCREENSPACE CLITERAL(Rectangle){ 0, 0, 1600, 900 }
#define CENTER CLITERAL(Vector2){ SCREENSPACE.width / 2, SCREENSPACE.height / 2 }

float Lerp(float s, float e, float i);
float Abs(float val);
double Abs(double val);

float Min(float val, float min);
float Max(float val, float max);
float Clamp(float val, float min, float max);

float GetAxis(const char *axis);
int GetAxisRaw(const char *axis);

string FloatToString(float val);
//size_t strLength(const char *string);