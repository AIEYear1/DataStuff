#pragma once
#include "Utils.h"
class SceneObject
{
protected:
	virtual void onUpdate();
	virtual void onInit();
public:
	Vec2 position;

	SceneObject();
	SceneObject(Vec2 pos);

	void init();
	void update();
};

