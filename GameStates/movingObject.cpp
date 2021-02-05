#include "movingObject.h"

movingObject::movingObject()
{
    minPoint = 0;
    maxPoint = 0;
    speed = 0;

    isHorizontal = false;
    travelFlip = false;
}
movingObject::movingObject(float spd, float min, float max, bool moveHorizontally, Rectangle objRec, Color objColor) : BoxObject(objRec, objColor)
{
    minPoint = min;
    maxPoint = max;
    speed = spd;

    isHorizontal = moveHorizontally;
    travelFlip = false;
}

void movingObject::onUpdate() 
{
    if (isHorizontal)
    {
        position.x += (speed * GetFrameTime()) * (travelFlip) ? -1 : 1;

        if (!travelFlip && position.x + rec.width > maxPoint)
        {
            position.x = maxPoint - rec.width;
            travelFlip = true;
        }
        else if (position.x < minPoint)
        {
            position.x = minPoint;
            travelFlip = false;
        }

        float offset = CENTER.x - ((Vec2)cameracenter::instance()).x;
        minPoint += offset;
        maxPoint += offset;

        return;
    }

    position.y += (speed * GetFrameTime()) * (travelFlip) ? -1 : 1;

    if (!travelFlip && position.y > maxPoint)
    {
        position.y = maxPoint;
        travelFlip = true;
    }
    else if (position.y < minPoint)
    {
        position.y = minPoint;
        travelFlip = false;
    }

    float offset = CENTER.y - ((Vec2)cameracenter::instance()).y;
    minPoint += offset;
    maxPoint += offset;
}