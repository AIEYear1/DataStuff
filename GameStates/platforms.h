#pragma once
#include <cstdio>
#include "SpriteObject.h"

class platforms
{


public:
	BoxObject **plats;
	int platformCount;

	void update();
	
	BoxObject *operator[](int);

	platforms();
	platforms(BoxObject *pltfrms[], int size);

	void destroy();
};
