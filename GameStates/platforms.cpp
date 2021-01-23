#include "platforms.h"

platforms::platforms()
{
	plats = nullptr;
	platformCount = 0;
}
platforms::platforms(BoxObject *pltfrms, int size)
{
	platformCount = size;
	plats = new BoxObject[size];
	for (int x = 0; x < size; ++x)
	{
		plats[x] = pltfrms[x];
	}
}

platforms::platforms(const platforms &other)
{
	platformCount = other.platformCount;
	plats = new BoxObject[platformCount];

	for (int x = 0; x < platformCount; ++x)
	{
		plats[x] = other.plats[x];
	}
}
platforms &platforms::operator=(const platforms &other)
{
	platformCount = other.platformCount;
	plats = new BoxObject[platformCount];

	for (int x = 0; x < platformCount; ++x)
	{
		plats[x] = other.plats[x];
	}

	return *this;
}
platforms::~platforms()
{
	delete[] plats;
}

BoxObject &platforms::operator[](int index)
{
	return plats[index];
}