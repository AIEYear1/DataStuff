#pragma once
#include "raylib.h"
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

bool onSegment(Vec2 p, Vec2 q, Vec2 r);

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Vec2 p, Vec2 q, Vec2 r);

// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Vec2 p1, Vec2 q1, Vec2 p2, Vec2 q2);