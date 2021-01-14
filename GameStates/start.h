#pragma once
#include "gamestate.h"
class start :
    public gamestate
{
protected:
    virtual void onInit() override;
    virtual void onDraw() override;
};

