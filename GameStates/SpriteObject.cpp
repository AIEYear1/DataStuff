#include "SpriteObject.h"

void SpriteObject::draw()
{
	onDraw();
}
SpriteObject::SpriteObject() : SceneObject()
{
	color = WHITE;
}
SpriteObject::SpriteObject(Color objColor, Vec2 pos, Vec2 *curcenter) : SceneObject(pos, curcenter)
{
	color = objColor;
}

void SpriteObject::onDraw() {}