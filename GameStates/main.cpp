#include "raylib.h"

#include "gamestate.h"
#include "start.h"
#include "Utils.h"

int main()
{
	InitWindow(SCREENSPACE.width, SCREENSPACE.height, "Test");
	SetTargetFPS(60);

	gamestate *states[]
	{
		new start()
	};

	int currentState = 0;

	states[currentState]->init();

	while (!WindowShouldClose() || currentState == -1)
	{
		states[currentState]->tick();
		states[currentState]->draw();

		int nextState = -1;
		if (states[currentState]->nextState(nextState))
		{
			states[currentState]->exit();

			currentState = nextState;

			states[currentState]->init();
		}
	}

	states[currentState]->exit();

	for (size_t x = 0; x < 1; ++x)
	{
		delete states[x];
	}

	CloseWindow();

	return 0;
}