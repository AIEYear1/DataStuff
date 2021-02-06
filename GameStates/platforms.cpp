#include "platforms.h"

platforms::platforms()
{
	plats = nullptr;
	platformCount = 0;
}
platforms::platforms(BoxObject *pltfrms[])
{
	platformCount = 0;
	BoxObject *tmpBox = pltfrms[0];
	while (tmpBox != nullptr)
	{
		++platformCount;
		tmpBox = pltfrms[platformCount];
	}

	plats = new BoxObject*[platformCount];
	for (int x = 0; x < platformCount; ++x)
	{
		plats[x] = pltfrms[x];
	}
}
void platforms::destroy()
{
	for (int x = 0; x < platformCount; ++x)
	{
		delete plats[x];
	}
	delete[] plats;
}

BoxObject *platforms::operator[](int index)
{
	return plats[index];
}


void platforms::update()
{
	for (int x = 0; x < platformCount; ++x)
	{
		plats[x]->update();
	}
}
void platforms::draw()
{
	for (int x = 0; x < platformCount; ++x)
	{
		plats[x]->draw();
	}
}