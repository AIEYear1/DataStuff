#include "MainGame.h"

Color MainGame::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void MainGame::generatePlatforms()
{
	Rectangle rec = Rectangle{ 0, CENTER.y + 120, SCREENSPACE.width, SCREENSPACE.height - (CENTER.y + 120) };
	platforms.push_back(BoxObject(rec, LIME, &curCenter));
}

void MainGame::onInit()
{
	curCenter = CENTER;
	platforms = std::vector<BoxObject>();
	generatePlatforms();

	plyr = Player(600, 1000, 1500, platforms, 30, ORANGE, curCenter, &curCenter);
}
void MainGame::onTick()
{
	plyr.update();

	for (int x = 0; x < platforms.size(); ++x)
	{
		platforms[x].update();
	}

	curCenter = CENTER;
}
void MainGame::onDraw()
{
	for (int x = 0; x < platforms.size(); ++x)
	{
		platforms[x].draw();
	}
	
	plyr.draw();
}