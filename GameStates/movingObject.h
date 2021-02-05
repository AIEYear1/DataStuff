#pragma once
#include "SpriteObject.h"
class movingObject :
    public BoxObject
{
    float maxPoint;
    float minPoint;
    float speed;

    bool isHorizontal;
    bool travelFlip;

    void onUpdate() override;

public:
    movingObject();
    movingObject(float spd, float min, float max, bool moveHorizontally, Rectangle objRec, Color objColor);
};

