#pragma once
#include <cstdio>
#include "SpriteObject.h"

class platforms
{
	BoxObject *plats;


public:
	int platformCount;
	
	BoxObject &operator[](int);

	platforms();
	platforms(BoxObject *pltfrms, int size);

	platforms(const platforms &other);
	platforms &operator=(const platforms &other);
	~platforms();
};
