#pragma once
#include "raylib.h"
#include "Utils.h"
class gamestate
{
protected:
	virtual Color background() const;

	virtual void onInit();
	virtual void onTick();
	virtual void onDraw();
	virtual void onExit();

public:
	void init();
	void tick();
	void draw();
	void exit();

	virtual bool nextState(int &nextState);
};
