#pragma once
#include "gamestate.h"
#include "Vec2.h"
class start :
    public gamestate
{
    Vec2 position;
    Rectangle box;

    void push();
protected:
    virtual Color background() const override;

    virtual void onInit() override;
    virtual void onTick() override;
    virtual void onDraw() override;
};

