#include "gamestate.h"
#include "raylib.h"

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

	ClearBackground(RAYWHITE);

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