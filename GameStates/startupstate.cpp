#include "startupstate.h"

Color startupstate::background() const
{
	return Color{ 13, 2, 33, 255 };
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