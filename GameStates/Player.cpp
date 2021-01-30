#include "Player.h"

Player::Player()
{
	vel = Vec2();

	spd = 300;
	jForce = 600;
	grav = 400;
	grounded = false;
	plats = nullptr;

	wallRide = 0;
	wallJumpLock = 0;

	dbJump = false;

	dashTimer = Timer(.1f);
	dashState = false;
	dashIsRight = false;
}

Player::Player(float speed, float jumpForce, float gravity, platforms &pltfrms, float objRadius, Color objColor, Vec2 pos) : CircleObject(objRadius, objColor, pos)
{
	vel = Vec2();
	spd = speed;
	jForce = jumpForce;
	grav = gravity;
	grounded = false;
	plats = &pltfrms;

	wallRide = 0;
	wallJumpLock = 0;

	dbJump = false;

	dashTimer = Timer(.1f);
	dashState = false;
	dashIsRight = false;
}

void Player::onInit()
{
	spawnPoint = SceneObject(CENTER);
	zero = SceneObject();

	showPos = UITextObject(position.ToString(), 50, Vec2(), SKYBLUE);
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
	wallRide = 0;
	//TODO: set wall ride to zero

	for (int x = 0; x < plats->platformCount; ++x)
	{
		if (CheckCollisionCircleRec(position, radius, (*plats)[x].rec))
		{
			push((*plats)[x]);
		}
	}

	showPos.str = (position - zero.position).ToString();

	cameracenter::instance().setPos(position);

	spawnPoint.update();
	zero.update();
}

void Player::onDraw()
{
	showPos.draw();

	DrawCircleV(position, radius, color);
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

		if (wallRide != 0 && vel.y > 0)
		{
			vel.y = (grav * 0.1f);

			if (wallJumpLock != wallRide && IsKeyPressed(KEY_SPACE))
			{
				vel.y = -jForce;
				wallJumpLock = wallRide;
			}
		}
		else
		{
			if (!dbJump && IsKeyPressed(KEY_SPACE))
			{
				vel.y = -jForce;
				dbJump = true;
			}

			vel.y += grav * GetFrameTime();
		}
	}

	switch (dashState)
	{
	case 0:
		if (IsKeyPressed(KEY_LEFT_SHIFT))
		{
			dashState = 1;
			dashIsRight = vel.x >= 0;
			vel = Vec2(spd * ((dashIsRight) ? 2.5 : -2.5), 0);
		}
		break;
	case 1:
		vel = Vec2(spd * ((dashIsRight) ? 2.5 : -2.5), 0);
		if (dashTimer.Check())
		{
			dashState = 2;
		}
		break;
	case 2:
		if (dashTimer.Check(false) && grounded)
		{
			dashTimer.Reset();
			dashState = 0;
		}
		break;
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

		dbJump = false;

		wallJumpLock = 0;
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
		wallRide = 1;
	}
	else if (angle < 0)
	{
		//// right
		position.x = colliding.position.x + colliding.rec.width + radius;

		//TODO: set wall ride to 2
		wallRide = 2;
	}
}