#pragma once
#include "SceneObject.h"
class SpriteObject :
    public SceneObject
{
protected:
    Color color;

    virtual void onDraw();

public:
    SpriteObject();
    SpriteObject(Color objColor, Vec2 pos, Vec2 *curcenter);

    void draw();
};

