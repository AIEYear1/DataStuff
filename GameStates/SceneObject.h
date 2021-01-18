#pragma once
#include "Utils.h"
class SceneObject
{
protected:
	Vec2 *curCenter;

	virtual void onUpdate();
	virtual void onInit();
public:
	Vec2 position;

	SceneObject();
	SceneObject(Vec2 pos, Vec2 *curcenter);

	void init();
	void update();
};

