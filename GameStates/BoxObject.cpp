#include "SpriteObject.h"

void BoxObject::onDraw()
{
	rec.x = position.x;
	rec.y = position.y;
	DrawRectangleRec(rec, color);
}

BoxObject::BoxObject() : SpriteObject()
{
	rec = Rectangle();
}

BoxObject::BoxObject(Rectangle objRec, Color objColor) : SpriteObject(objColor)
{
	rec = objRec;
	position = Vec2(objRec.x, objRec.y);
}