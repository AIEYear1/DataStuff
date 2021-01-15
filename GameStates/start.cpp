#include "start.h"
#include "raylib.h"
#include "tList.h"

Color start::background() const
{
	return MAGENTA;
}

void start::onInit()
{
	position = CENTER;
	box = Rectangle{ 1000, 100, 300, 300 };
}

void start::onTick()
{
	Vec2 vel = Vec2(GetAxis("Horizontal"), GetAxis("Vertical"));
	vel.ClampMagnitude(1);

	position += vel * 300 * GetFrameTime();

	if (CheckCollisionCircleRec(position, 20, box))
	{
		push();
	}
}

void start::onDraw()
{
	DrawRectangleRec(box, BLUE);
	DrawCircle(position.x, position.y, 20, BLACK);
}

void start::push()
{
	Vec2 push = Vec2();
	float boxSpacerThing = 0;
	Vec2 boxCenter = Vec2(box.x + (box.width / 2), box.y + (box.height / 2));

	float angle = Vec2(0, -1).SignedAngle(position - boxCenter);
	float uAngle = Abs(angle);
	
	if (uAngle < 45)
	{
		//// up
		position.y -= Abs((boxCenter.y - position.y) - ((box.height / 2) + 20));
	}
	else if (uAngle > 135)
	{
		//// down
		position.y += Abs((position.y - boxCenter.y) - ((box.height / 2) + 20));
	}
	else if (angle > 0)
	{
		//// left
		position.x -= Abs((boxCenter.x - position.x) - ((box.width / 2) + 20));
	}
	else if (angle < 0)
	{
		//// right
		position.x += Abs((position.x - boxCenter.x) - ((box.width / 2) + 20));
	}
}