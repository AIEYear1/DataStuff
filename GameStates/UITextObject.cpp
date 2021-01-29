#include "UITextObject.h"

UITextObject::UITextObject() : UIObject()
{
	str = string();
	size = 0;
}
UITextObject::UITextObject(string text, size_t fontSize, Vec2 pos, Color clr) : UIObject(pos, clr)
{
	str = text;
	size = fontSize;
}

void UITextObject::onDraw()
{
	DrawText(str, position.x, position.y, size, color);
}