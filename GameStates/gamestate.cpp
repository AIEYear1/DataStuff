#include "gamestate.h"

Color gamestate::background() const
{
	return RAYWHITE;
}

void gamestate::init()
{
	onInit();
}
void gamestate::tick()
{
	onTick();
}
void gamestate::draw()
{
	BeginDrawing();

	ClearBackground(background());

	onDraw();

	EndDrawing();
}
void gamestate::exit()
{
	onExit();
}
void gamestate::onInit() {}
void gamestate::onTick() {}
void gamestate::onDraw() {}
void gamestate::onExit() {}

bool gamestate::nextState(int &nextState) { return false; }