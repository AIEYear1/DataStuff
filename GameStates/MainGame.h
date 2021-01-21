#pragma once
#include "gamestate.h"
#include "SpriteObject.h"
#include <vector>
#include "Player.h"

class MainGame :
    public gamestate
{
    Vec2 curCenter;
    Player plyr;
    std::vector<BoxObject> platforms;

    void generatePlatforms();
protected:
    virtual Color background() const override;

    virtual void onInit() override;
    virtual void onTick() override;
    virtual void onDraw() override;
};

