#pragma once
#include "CircleObject.h"
class Player :
    public CircleObject
{
    Vec2 vel;

    float spd;
    float jForce;
    float grav;

    virtual void onUpdate() override;

    void move();
    bool isGrounded();

    void push(SpriteObject colliding);
public:
    Player();
    Player(float speed, float jumpForce, float gravity, float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter);
};

