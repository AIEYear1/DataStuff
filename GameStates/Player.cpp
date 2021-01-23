#include "Player.h"

Player::Player()
{
	vel = Vec2();

	spd = 300;
	jForce = 600;
	grav = 400;
	grounded = false;
	plats = nullptr;
}

Player::Player(float speed, float jumpForce, float gravity, platforms &pltfrms, float objRadius, Color objColor, Vec2 pos) : CircleObject(objRadius, objColor, pos)
{
	vel = Vec2();
	spd = speed;
	jForce = jumpForce;
	grav = gravity;
	grounded = false;
	plats = &pltfrms;
}

void Player::onUpdate()
{
	move();

	if (position.y > spawnPoint.position.y + 2000)
	{
		position = spawnPoint.position;
		vel = Vec2();
	}

	grounded = false;
	//TODO: set wall ride to zero

	for (int x = 0; x < plats->platformCount; ++x)
	{
		if (CheckCollisionCircleRec(position, radius, (*plats)[x].rec))
		{
			push((*plats)[x]);
		}
	}

	cameracenter::instance().setPos(position);

	spawnPoint.update();
}

void Player::move()
{
	vel.x = GetAxis("Horizontal") * spd;
	//vel.y = curCenter->y;

	// Jump code
	if (grounded)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			vel.y = -jForce;
		}
	}
	else
	{
		//TODO: check for double jump bool and space input if both good set double jump bool to true and set vel.y = -(jForce * 0.75f)

		//TODO: check for a wall ride and if so set grav pull to (grav *0.2f) *GetFrameTIme() and allow for wall jump then wall jump lock

		vel.y += grav * GetFrameTime();
	}

	position += vel * GetFrameTime();
}

void Player::push(BoxObject &colliding)
{
	Vec2 push = Vec2();
	float boxSpacerThing = 0;
	Vec2 boxCenter = Vec2(colliding.rec.x + (colliding.rec.width / 2), colliding.rec.y + (colliding.rec.height / 2));

	float angle = Vec2(0, -1).SignedAngle(position - boxCenter);
	float uAngle = Abs(angle);

	float lowerExtent = Vec2(0, -1).AngleBetween(Vec2(colliding.rec.x, colliding.rec.y) - boxCenter);
	float upperExtent = Vec2(0, -1).AngleBetween(Vec2(colliding.rec.x + colliding.rec.width, colliding.rec.y + colliding.rec.height) - boxCenter);

	if (uAngle < lowerExtent)
	{
		//// up
		position.y = colliding.position.y - radius;
		grounded = true;
		vel.y = 0;

		//TODO: set double jump bool to false
	}
	else if (uAngle > upperExtent)
	{
		//// down
		position.y = colliding.position.y + colliding.rec.height + radius;
		vel.y = 0;
	}
	else if (angle > 0)
	{
		//// left
		position.x = colliding.position.x - radius;

		//TODO: set wall ride to 1
	}
	else if (angle < 0)
	{
		//// right
		position.x = colliding.position.x + colliding.rec.width + radius;

		//TODO: set wall ride to 2
	}
}