#pragma once
class gamestate
{
protected:
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

