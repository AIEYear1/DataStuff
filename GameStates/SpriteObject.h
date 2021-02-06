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
    SpriteObject(Color objColor);
    SpriteObject(Color objColor, Vec2 pos);

    void draw();
};

class CircleObject :
    public SpriteObject
{
protected:
    virtual void onDraw() override;

public:
    float radius;

    CircleObject();
    CircleObject(float objRadius, Color objColor, Vec2 pos);
};

class BoxObject :
    public SpriteObject
{
protected:
    virtual void onDraw() override;

public:
    Rectangle rec;

    BoxObject();
    BoxObject(Rectangle objRec, Color objColor);

    virtual void onCollision(SpriteObject &colliding);
};

class TextObject :
    public SpriteObject
{
protected:
    virtual void onDraw() override;

public:
    string text;
    size_t size;

    TextObject();
    TextObject(string txt, size_t fontSize, Color objColor, Vec2 pos);
};