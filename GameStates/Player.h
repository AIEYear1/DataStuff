#pragma once
#include "SpriteObject.h"
#include "platforms.h"
#include "UITextObject.h"
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
    bool dbJump;
    //TODO: int for wall ride; 0 for neither, 1 for left side, 2 for right side
    //TODO: int for wall jump lock; 0 for neither, 1 for left side, 2 for right side
    int wallRide;
    int wallJumpLock;

    // consider a dash function, probably timer based
    Timer dashTimer;
    int dashState;
    bool dashIsRight;
    // perhaps an enhanced camera follow to help see around

    //Momentum horizontal

    UITextObject showPos;
    virtual void onInit() override;
    virtual void onUpdate() override;
    virtual void onDraw() override;

    void move();

    void push(BoxObject &colliding);

public:
    SceneObject spawnPoint;
    SceneObject zero;

    Player();
    Player(float speed, float jumpForce, float gravity, platforms &pltfrms, float objRadius, Color objColor, Vec2 pos);
};

