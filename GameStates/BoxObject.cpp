#include "BoxObject.h"

void BoxObject::onDraw()
{
	DrawRectangleRec(rec, color);
}

BoxObject::BoxObject() : SpriteObject()
{
	rec = Rectangle();
}

BoxObject::BoxObject(Rectangle &objRec, Color objColor, Vec2 pos, Vec2 *curcenter) : SpriteObject(objColor, pos, curcenter)
{
	rec = objRec;
}