#pragma once
#include "Vec2.h"
#include "Utils.h"
class cameracenter
{
public:
	static cameracenter &instance();

	operator Vec2();
	void setPos(Vec2 position);
private:
	Vec2 pos;
	cameracenter();
};

