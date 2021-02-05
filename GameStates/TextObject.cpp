#include "SpriteObject.h"

TextObject::TextObject()
{
	text = string();
	size = 0;
}
TextObject::TextObject(string txt, size_t fontSize, Color objColor, Vec2 pos) : SpriteObject(objColor, pos)
{
	text = txt;
	size = fontSize;
}

void TextObject::onDraw()
{
	DrawText(text, position.x, position.y, size, color);
}