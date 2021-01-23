#include "startupstate.h"

Color startupstate::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void startupstate::onDraw()
{
	DrawText("The Perfect Platformer Name", 200, 200, 80, LIME);

	DrawText("press space to start", 700, CENTER.y + 200, 20, DARKGREEN);
}

bool startupstate::nextState(int &nextState)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		nextState = 1;
		return true;
	}

	return false;
}