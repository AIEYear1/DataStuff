#pragma once
#include "gamestate.h"
class MainGame :
    public gamestate
{
    Vec2 curCenter;

protected:
    virtual Color background() const override;

    virtual void onInit() override;
    virtual void onTick() override;
    virtual void onDraw() override;
};

