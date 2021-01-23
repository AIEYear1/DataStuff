#include "MainGame.h"

Color MainGame::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void MainGame::onInit()
{
	generatePlatforms();

	plyr = Player(800, 1000, 2500, plats, 30, ORANGE, CENTER);
	plyr.spawnPoint = SceneObject(CENTER);

	otherObjs[4] =
	{
		SpriteObject(MAROON, Vec2()),
	};
}
void MainGame::onTick()
{
	plyr.update();

	for (int x = 0; x < plats.platformCount; ++x)
	{
		plats[x].update();
	}

	cameracenter::instance().setPos(CENTER);
}
void MainGame::onDraw()
{
	for (int x = 0; x < plats.platformCount; ++x)
	{
		plats[x].draw();
	}
	
	plyr.draw();
}

void MainGame::generatePlatforms()
{
	BoxObject tmp[]
	{
		BoxObject(Rectangle{ -25, 50, 25, 800 },   LIME),
		BoxObject(Rectangle{ 0, 550, 1100, 300 },  LIME),
		BoxObject(Rectangle{ 1100, 350, 500, 500 }, LIME),
		BoxObject(Rectangle{ 2200, 350, 650, 500 }, LIME),
		BoxObject(Rectangle{ 3350, 100, 650, 100 }, LIME),
		BoxObject(Rectangle{ 3600, 400, 650, 500 }, LIME),
	};
	plats = platforms(tmp, sizeof(tmp) / sizeof(tmp[0]));
}