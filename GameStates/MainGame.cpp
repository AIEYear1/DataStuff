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

	objSize = 5;
	otherObjs = new SpriteObject*[]
	{
		new TextObject("  AD to move\nspace to jump", 16, DARKRED, Vec2(1150, 425)),
		new TextObject("use the bottom ledge\n  to make the jump", 16, DARKRED, Vec2(3375, 125)),
		new TextObject(" jump while wall sliding\nto perform a wall jump", 16, DARKRED, Vec2(3675, -200)),
		new TextObject("shift to dash", 16, DARKRED, Vec2(4925, -350)),
		new TextObject("   jump while in the air\nto perform a double jump", 16, DARKRED, Vec2(6525, -575)),
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
		BoxObject(Rectangle{ -400, 50, 400, 800 },   LIME), // back wall
		BoxObject(Rectangle{ 0, 550, 1100, 300 },  LIME), // start platform
		BoxObject(Rectangle{ 1100, 350, 500, 500 }, LIME), // first platform
		BoxObject(Rectangle{ 2200, 350, 650, 500 }, LIME), // second platform
		BoxObject(Rectangle{ 3450, 100, 550, 100 }, LIME), // ledge
		BoxObject(Rectangle{ 3550, 400, 700, 500 }, LIME), // landing platform
		BoxObject(Rectangle{ 4250, 300, 200, 600 }, LIME), // step stool
		BoxObject(Rectangle{ 4000, 150, 100, 50 }, LIME), // ledge lip
		BoxObject(Rectangle{ 4450, -125, 100, 1025 }, LIME), // right wall
		BoxObject(Rectangle{ 3350, -1300, 100, 1500 }, LIME), // wall jump wall
		BoxObject(Rectangle{ 3650, -225, 1200, 100 }, LIME), // wall jump platform
		BoxObject(Rectangle{ 5100, -225, 600, 100 }, LIME), // dash platform
		BoxObject(Rectangle{ 4500, -1300, 1200, 995 }, LIME), // dash ceiling
		BoxObject(Rectangle{ 5700, -225, 2100, 1075 }, LIME), // Double Jump floor
		BoxObject(Rectangle{ 6500, -600, 1200, 100 }, LIME), // Double Jump platform
		BoxObject(Rectangle{ 7700, -1300, 100, 1075 }, LIME), // Double Jump wall
	};
	plats = platforms(tmp, sizeof(tmp) / sizeof(tmp[0]));
}