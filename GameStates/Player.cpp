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
	dashState = 0;
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
	dashState = 0;
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

	for (int x = 0; x < plats->platformCount; ++x)
	{
		if (CheckCollisionCircleRec(position, radius, (*plats)[x]->rec))
		{
			push(*(*plats)[x]);
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
	horizontal();
	vertical();

	position += vel * GetFrameTime();
}
void Player::horizontal()
{
	switch (dashState)
	{
	case 0:
		if (vel.x != 0 && IsKeyPressed(KEY_LEFT_SHIFT))
		{
			dashState = 1;
			vel = Vec2(spd * ((vel.x > 0) ? 2.5 : -2.5), 0); // fix this to twixe max speed when done

			return;
		}
		break;
	case 1:
		//vel.x = spd * ((dashIsRight) ? 2.5 : -2.5);

		if (dashTimer.Check())
		{
			dashState = 2;

			break;
		}
		return;
	case 2:
		if (dashTimer.Check(false) && grounded)
		{
			dashTimer.Reset();
			dashState = 0;
		}
		break;
	}
	vel.x = GetAxis("Horizontal") * spd;

	/// start by getting input
	/// if input is 0 and grounded set vel.x to 0
	/// cur speed = abs(vel.x)
	/// compare input to current vel.x
	/// if in the same direction increment towards max speed
	///		if cur speed is less than max speed    increment = aceleration * GetFrameTime()
	///			if max speed - cur speed < increment    increment = max speed - vel.x
	///		vel.x += increment * input;
	///		if cur speed is greater than max speed    vel.x = max speed
	/// if in contrasting direction 
	///		if grounded set input to 0 
	/// then increment towards max speed
	///		vel.x = input * aceleration * GetFrameTime()

}
void Player::vertical()
{
	// stop falling while dashing
	if (dashState == 1)
	{
		return;
	}

	// Grounded
	if (grounded)
	{
		if (IsKeyPressed(KEY_SPACE))
		{
			vel.y = -jForce;
		}

		return;
	}

	// Wall Ride
	if (wallRide != 0)
	{
		if (vel.y > 0)
			vel.y = (grav * 0.1f);
		else
			vel.y += grav * GetFrameTime();

		if (wallJumpLock != wallRide && IsKeyPressed(KEY_SPACE))
		{
			vel.y = -jForce;
			// set vel.x to max speed
			wallJumpLock = wallRide;
		}

		return;
	}

	// Free Fall
	if (!dbJump && IsKeyPressed(KEY_SPACE))
	{
		vel.y = -jForce;
		dbJump = true;
	}

	vel.y += grav * GetFrameTime();
}

void Player::push(BoxObject &colliding)
{
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

		dbJump = false;
		wallJumpLock = 0;

		return;
	}
	if (uAngle > upperExtent)
	{
		//// down
		position.y = colliding.position.y + colliding.rec.height + radius;
		vel.y = 0;

		return;
	}
	if (angle > 0)
	{
		//// left
		position.x = colliding.position.x - radius;

		vel.x = 0;
		wallRide = 1;

		return;
	}
	if (angle < 0)
	{
		//// right
		position.x = colliding.position.x + colliding.rec.width + radius;

		vel.x = 0;
		wallRide = 2;

		return;
	}
}