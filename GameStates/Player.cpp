#include "Player.h"

Player::Player()
{
	vel = Vec2();

	spd = 300;
	jForce = 600;
	grav = 400;
}

Player::Player(float speed, float jumpForce, float gravity, float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter) : CircleObject(objRadius, objColor, pos, curcenter)
{
	vel = Vec2();
	spd = speed;
	jForce = jumpForce;
	grav = gravity;
}

void Player::onUpdate()
{
	move();
}

void Player::move()
{
	vel.x = GetAxis("Horizontal") * spd;
	vel.y = curCenter->y;

	// Jump code
	if (isGrounded())
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			vel.y = jForce;
		}
	}
	else
	{
		vel.y -= grav * GetFrameTime();
	}

	*curCenter += vel;

	position += *curCenter - (Vec2)CENTER;
}

bool Player::isGrounded()
{
	Vec2 rayBottom = Vec2(0, radius * .6f);

	//Find box below player
	return doIntersect(position, rayBottom - position, );
}