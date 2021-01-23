#include "SceneObject.h"

void SceneObject::init()
{
	onInit();
}

void SceneObject::update()
{
	onUpdate();
	// Camera follow

	position += (Vec2)CENTER - cameracenter::instance();
}
SceneObject::SceneObject()
{
	position = Vec2();
}
SceneObject::SceneObject(Vec2 pos)
{
	position = pos;
}

void SceneObject::onInit() {}
void SceneObject::onUpdate() {}