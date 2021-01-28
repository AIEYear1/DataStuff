#pragma once
#include "gamestate.h"
#include "SpriteObject.h"
#include "Player.h"
#include "platforms.h"

class MainGame :
    public gamestate
{
    Player plyr;
    platforms plats;
    SpriteObject **otherObjs;

    void generatePlatforms();
protected:
    virtual Color background() const override;

    virtual void onInit() override;
    virtual void onTick() override;
    virtual void onDraw() override;
    virtual void onExit() override;
};

