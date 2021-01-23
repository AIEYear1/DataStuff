#include "SpriteObject.h"

void CircleObject::onDraw()
{
	DrawCircleV(position, radius, color);
}

CircleObject::CircleObject() : SpriteObject()
{
	radius = 0;
}

CircleObject::CircleObject(float objRadius, Color objColor, Vec2 pos) : SpriteObject(objColor, pos)
{
	radius = objRadius;
}