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

    bool dbJump;
    int wallRide;
    int wallJumpLock;

    Timer dashTimer;
    int dashState;

    // perhaps an enhanced camera follow to help see around

    // Momentum horizontal
    // float acceleration for how fast you speed up towards max speed
    // float max speed probably just change the name of spd
    // possible float deceleration while in the air

    // Debug to make it easier to find positions for objects
    UITextObject showPos;

    virtual void onInit() override;
    virtual void onUpdate() override;
    virtual void onDraw() override;

    void move();
    void horizontal();
    void vertical();

    void push(BoxObject &colliding);

public:
    SceneObject spawnPoint;
    SceneObject zero;

    Player();
    Player(float speed, float jumpForce, float gravity, platforms &pltfrms, float objRadius, Color objColor, Vec2 pos);
};

