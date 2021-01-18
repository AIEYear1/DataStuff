#pragma once
#include "SpriteObject.h"
class BoxObject :
    public SpriteObject
{
public:
    Rectangle rec;

    BoxObject();
    BoxObject(Rectangle &objRec, Color objColor, Vec2 pos, Vec2 *curcenter);

    virtual void onDraw() override;
};

