#include "movingObject.h"

movingObject::movingObject()
{
    speed = 0;
    minPoint = 0;
    maxPoint = 0;

    isHorizontal = false;
    travelFlip = false;

    displacement = 0;
}
movingObject::movingObject(float spd, float min, float max, bool moveHorizontally, Rectangle objRec, Color objColor) : BoxObject(objRec, objColor)
{
    speed = spd;
    minPoint = min;
    maxPoint = max;

    isHorizontal = moveHorizontally;
    travelFlip = false;

    displacement = 0;
}

void movingObject::onUpdate() 
{
    if (isHorizontal)
    {
        displacement = speed * GetFrameTime() * ((travelFlip) ? -1.0f : 1.0f);
        position.x += displacement;

        if (!travelFlip && position.x + rec.width > maxPoint)
        {
            displacement -= position.x - (maxPoint - rec.width);
            position.x = maxPoint - rec.width;
            travelFlip = true;
        }
        else if (position.x < minPoint)
        {
            displacement -= position.x - minPoint;
            position.x = minPoint;
            travelFlip = false;
        }

        float offset = CENTER.x - ((Vec2)cameracenter::instance()).x;
        minPoint += offset;
        maxPoint += offset;

        return;
    }

    displacement = speed * GetFrameTime() * ((travelFlip) ? -1.0f : 1.0f);
    position.y += displacement;

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
void movingObject::onCollision(SpriteObject &colliding)
{
    if (isHorizontal)
    {
        colliding.position.x += displacement;
        return;
    }

    colliding.position.y += displacement;
}