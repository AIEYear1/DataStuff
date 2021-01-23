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
    virtual void onDraw() override;

public:
    float radius;

    CircleObject();
    CircleObject(float objRadius, Color objColor, Vec2 pos);
};

class BoxObject :
    public SpriteObject
{
    virtual void onDraw() override;
    virtual void onUpdate() override;

public:
    Rectangle rec;

    BoxObject();
    BoxObject(Rectangle objRec, Color objColor);
};

class TextObject :
    public SpriteObject
{
    virtual void onDraw() override;

public:
    const char *text;
    size_t size;

    TextObject();
    TextObject(const char *txt, size_t fontSize, Color objColor, Vec2 pos);
};