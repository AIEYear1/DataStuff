#include "cameracenter.h"

cameracenter::cameracenter()
{
    pos = CENTER;
}

cameracenter &cameracenter::instance()
{
    static cameracenter *instance = new cameracenter();
    return *instance;
}
void cameracenter::setPos(Vec2 position)
{
    pos = position;
}

cameracenter::operator Vec2()
{
    return pos;
}