#include "MainGame.h"

Color MainGame::background() const
{
	return Color{ 13, 2, 33, 255 };
}

void MainGame::onInit()
{
	generatePlatforms();

	plyr = Player(800, 1000, 2500, plats, 30, ORANGE, CENTER);
	plyr.init();

	objSize = 2;
	otherObjs = new SpriteObject*[]
	{
		new TextObject("  AD to move\nspace to jump", 16, DARKGREEN, Vec2(700, 250)),
		new TextObject("use the bottom ledge\n  to make the jump", 16, DARKGREEN, Vec2(3000, 150)),
	};
}
void MainGame::onTick()
{
	plyr.update();

	for (int x = 0; x < plats.platformCount; ++x)
	{
		plats[x].update();
	}

	for (int x = 0; x < objSize; ++x)
	{
		otherObjs[x]->update();
	}

	cameracenter::instance().setPos(CENTER);
}
void MainGame::onDraw()
{
	for (int x = 0; x < plats.platformCount; ++x)
	{
		plats[x].draw();
	}

	for (int x = 0; x < objSize; ++x)
	{
		otherObjs[x]->draw();
	}
	
	plyr.draw();
}
void MainGame::onExit()
{
	for (int x = 0; x < objSize; ++x)
	{
		delete otherObjs[x];
	}

	delete[] otherObjs;
}

void MainGame::generatePlatforms()
{
	BoxObject tmp[]
	{
		BoxObject(Rectangle{ -25, 50, 25, 800 },   LIME), // back wall
		BoxObject(Rectangle{ 0, 550, 1100, 300 },  LIME), // start platform
		BoxObject(Rectangle{ 1100, 350, 500, 500 }, LIME), // first platform
		BoxObject(Rectangle{ 2200, 350, 650, 500 }, LIME), // second platform
		BoxObject(Rectangle{ 3450, 100, 550, 100 }, LIME), // ledge
		BoxObject(Rectangle{ 3550, 400, 700, 500 }, LIME), // landing platform
		BoxObject(Rectangle{ 4250, 300, 200, 600 }, LIME), // step stool
		BoxObject(Rectangle{ 4000, 150, 100, 50 }, LIME), // ledge lip
		BoxObject(Rectangle{ 4450, -430, 100, 1330 }, LIME), // right wall
		BoxObject(Rectangle{ 3350, -1100, 100, 1300 }, LIME), // wall jump
		BoxObject(Rectangle{ 3650, -225, 800, 100 }, LIME), // wall jump platform
	};
	plats = platforms(tmp, sizeof(tmp) / sizeof(tmp[0]));
}