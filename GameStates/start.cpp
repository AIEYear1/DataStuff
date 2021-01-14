#include "start.h"
#include "raylib.h"
#include "tList.h"

void start::onInit()
{
	tList<int> list = tList<int>();

	list.push_front(7);
	list.push_front(6);
	list.push_front(2);
	list.push_front(8);
	list.push_front(4);
	list.push_front(9);

	list.remove(2);

	list.front();
}
void start::onDraw()
{
	DrawText("Hello", 200, 300, 15, BLACK);
}