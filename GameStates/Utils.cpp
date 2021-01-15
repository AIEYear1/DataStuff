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