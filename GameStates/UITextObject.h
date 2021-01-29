#pragma once
#include "UIObject.h"
#include "string.h"
class UITextObject :
    public UIObject
{
    virtual void onDraw() override;

public:
    string str;
    size_t size;

    UITextObject();
    UITextObject(string text, size_t fontSize, Vec2 pos, Color clr);
};

