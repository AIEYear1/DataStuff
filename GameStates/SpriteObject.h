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
    SpriteObject(Color objColor, Vec2 *curcenter);
    SpriteObject(Color objColor, Vec2 pos, Vec2 *curcenter);

    void draw();
};

class CircleObject :
    public SpriteObject
{
    virtual void onDraw() override;

public:
    float radius;

    CircleObject();
    CircleObject(float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter);
};

class BoxObject :
    public SpriteObject
{
    virtual void onDraw() override;
    virtual void onUpdate() override;

public:
    Rectangle rec;

    BoxObject();
    BoxObject(Rectangle &objRec, Color objColor, Vec2 *curcenter);
};