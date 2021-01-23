#include "SpriteObject.h"

void SpriteObject::draw()
{
	onDraw();
}
SpriteObject::SpriteObject() : SceneObject()
{
	color = WHITE;
}
SpriteObject::SpriteObject(Color objColor) : SceneObject()
{
	color = objColor;
}
SpriteObject::SpriteObject(Color objColor, Vec2 pos) : SceneObject(pos)
{
	color = objColor;
}

void SpriteObject::onDraw() {}