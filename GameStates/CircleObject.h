#pragma once
#include "SpriteObject.h"
class CircleObject :
    public SpriteObject
{
public:
    float radius;

    CircleObject();
    CircleObject(float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter);

    virtual void onDraw() override;
};

