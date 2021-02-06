#pragma once
#include <cstdio>
#include "SpriteObject.h"

class platforms
{


public:
	BoxObject **plats;
	int platformCount;

	void update();
	void draw();
	
	BoxObject *operator[](int);

	platforms();
	platforms(BoxObject *pltfrms[]);

	void destroy();
};
