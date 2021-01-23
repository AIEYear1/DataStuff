#pragma once
#include "SpriteObject.h"
#include "platforms.h"
class Player :
    public CircleObject
{
    Vec2 vel;

    float spd;
    float jForce;
    float grav;
    bool grounded;
    platforms *plats;

    //TODO: bool for double jump
    //TODO: int for wall ride; 0 for neither, 1 for left side, 2 for right side
    //TODO: int for wall jump lock; 0 for neither, 1 for left side, 2 for right side

    virtual void onUpdate() override;

    void move();

    void push(BoxObject &colliding);

public:
    SceneObject spawnPoint;

    Player();
    Player(float speed, float jumpForce, float gravity, platforms &pltfrms, float objRadius, Color objColor, Vec2 pos);
};

