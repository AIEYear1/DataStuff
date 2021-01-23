#include "SpriteObject.h"

TextObject::TextObject()
{
	text = "";
	size = 0;
}
TextObject::TextObject(const char *txt, size_t fontSize, Color objColor, Vec2 pos) : SpriteObject(objColor, pos)
{
	text = txt;
	size = fontSize;
}

void TextObject::onDraw()
{
	DrawText(text, position.x, position.y, size, color);
}