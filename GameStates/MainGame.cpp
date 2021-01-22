#include "MainGame.h"

Color MainGame::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void MainGame::generatePlatforms()
{
	platforms.push_back(BoxObject(Rectangle{ -25, 70, 25, 830 }, LIME, &curCenter));
	platforms.push_back(BoxObject(Rectangle{ 0, 570, 1600, 330 }, LIME, &curCenter));
	platforms.push_back(BoxObject(Rectangle{ 1100, 220, 500, 350 }, LIME, &curCenter));
}

void MainGame::onInit()
{
	curCenter = CENTER;
	platforms = std::vector<BoxObject>();
	generatePlatforms();

	plyr = Player(800, 1200, 2000, platforms, 30, ORANGE, curCenter, &curCenter);
	plyr.spawnPoint = SceneObject(CENTER, &curCenter);
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