#include "Utils.h"

float Lerp(float s, float e, float i)
{
    return s + ((e - s) * i);
}
float Abs(float val)
{
    return (val > 0) ? val : -val;
}
double Abs(double val)
{
    return (val > 0) ? val : -val;
}

float Min(float val, float min)
{
    return (val > min) ? val : min;
}
float Max(float val, float max)
{
    return (val < max) ? val : max;
}
float Clamp(float val, float min, float max)
{
    return (val < max) ? (val > min) ? val : min : max;
}

float toReturnHorizontal = 0, toReturnVertical = 0;
float GetAxis(const char *axis)
{
    float sensitivity = 5;
    //How small the number has to be to not be registered
    float dead = .001f;
    //what the axis will try and reach
    float target = 0;

    //1st case "Vertical", returns between 1 (S key) and -1 (W key)
    if (axis == "Vertical")
    {
        if (IsKeyDown(KEY_W))
            target = -1;
        if (IsKeyDown(KEY_S))
            target = 1;

        toReturnVertical = Lerp(toReturnVertical, target, sensitivity * GetFrameTime());
        return (Abs(toReturnVertical) < dead) ? 0.0f : toReturnVertical;
    }
    //2nd case "Horizontal", returns between 1 (D key) and -1 (A key)
    if (axis == "Horizontal")
    {
        if (IsKeyDown(KEY_D))
            target = 1;
        if (IsKeyDown(KEY_A))
            target = -1;

        toReturnHorizontal = Lerp(toReturnHorizontal, target, sensitivity * GetFrameTime());
        return (Abs(toReturnHorizontal) < dead) ? 0.0f : toReturnHorizontal;
    }

    return 0;
}

bool onSegment(Vec2 p, Vec2 q, Vec2 r)
{
    if (q.x <= Max(p.x, r.x) && q.x >= Min(p.x, r.x) &&
        q.y <= Max(p.y, r.y) && q.y >= Min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Vec2 p, Vec2 q, Vec2 r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear 

    return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(Vec2 p1, Vec2 q1, Vec2 p2, Vec2 q2)
{
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case 
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases 
}