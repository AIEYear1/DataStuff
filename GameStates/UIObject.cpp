#include "UIObject.h"

UIObject::UIObject()
{
	position = Vec2();
	color = RAYWHITE;
}
UIObject::UIObject(Vec2 pos, Color clr)
{
	position = pos;
	color = clr;
}

void UIObject::init()
{
	onInit();
}
void UIObject::update()
{
	onUpdate();
}
void UIObject::draw()
{
	onDraw();
}

void UIObject::onInit() {}
void UIObject::onUpdate() {}
void UIObject::onDraw() {}