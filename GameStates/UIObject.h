#pragma once
#include "raylib.h"
#include "Vec2.h"

class UIObject
{
protected:
	virtual void onUpdate();
	virtual void onInit();
	virtual void onDraw();

public:
	Vec2 position;
	Color color;

	UIObject();
	UIObject(Vec2 pos, Color clr);

	void init();
	void update();
	void draw();
};

