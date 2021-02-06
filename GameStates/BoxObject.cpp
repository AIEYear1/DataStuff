#include "SpriteObject.h"

BoxObject::BoxObject() : SpriteObject()
{
	rec = Rectangle();
}
BoxObject::BoxObject(Rectangle objRec, Color objColor) : SpriteObject(objColor)
{
	rec = objRec;
	position = Vec2(objRec.x, objRec.y);
}

void BoxObject::onDraw()
{
	rec.x = position.x;
	rec.y = position.y;
	DrawRectangleRec(rec, color);
}

void BoxObject::onCollision(SpriteObject &colliding) {}