#include "SceneObject.h"

void SceneObject::init()
{
	onInit();
}

void SceneObject::update()
{
	onUpdate();
	// Camera follow

	position += (Vec2)CENTER - *curCenter;
}
SceneObject::SceneObject()
{
	position = Vec2();
	curCenter = nullptr;
}
SceneObject::SceneObject(Vec2 pos, Vec2 *curcenter)
{
	position = pos;
	curCenter = curcenter;
}

void SceneObject::onInit() {}
void SceneObject::onUpdate() {}