#pragma once
#include "SpriteObject.h"
#include <vector>
class Player :
    public CircleObject
{
    Vec2 vel;

    float spd;
    float jForce;
    float grav;
    bool grounded;
    std::vector<BoxObject> *platforms;

    virtual void onUpdate() override;

    void move();
    bool isGrounded();

    void push(BoxObject &colliding);
public:
    Player();
    Player(float speed, float jumpForce, float gravity, std::vector<BoxObject> &pltfrms, float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter);
};

