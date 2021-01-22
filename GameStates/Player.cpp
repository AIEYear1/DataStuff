#include "Player.h"

Player::Player()
{
	vel = Vec2();

	spd = 300;
	jForce = 600;
	grav = 400;
	grounded = false;
	platforms = nullptr;
}

Player::Player(float speed, float jumpForce, float gravity, std::vector<BoxObject> &pltfrms, float objRadius, Color objColor, Vec2 pos, Vec2 *curcenter) : CircleObject(objRadius, objColor, pos, curcenter)
{
	vel = Vec2();
	spd = speed;
	jForce = jumpForce;
	grav = gravity;
	grounded = false;
	platforms = &pltfrms;
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
	for (int x = 0; x < platforms->size(); ++x)
	{
		if (CheckCollisionCircleRec(position, radius, (*platforms)[x].rec))
		{
			push((*platforms)[x]);
		}
	}

	*curCenter = position;

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
		//position.y -= Abs((boxCenter.y - position.y) - ((colliding.rec.height / 2) + radius));
		grounded = true;
		vel.y = 0;
	}
	else if (uAngle > upperExtent)
	{
		//// down
		position.y = colliding.position.y + colliding.rec.height + radius;
		//position.y += Abs((position.y - boxCenter.y) - ((colliding.rec.height / 2) + radius));
		vel.y = 0;
	}
	else if (angle > 0)
	{
		//// left
		position.x = colliding.position.x - radius;
		//position.x -= Abs((boxCenter.x - position.x) - ((colliding.rec.width / 2) + radius));
	}
	else if (angle < 0)
	{
		//// right
		position.x = colliding.position.x + colliding.rec.width + radius;
		//position.x += Abs((position.x - boxCenter.x) - ((colliding.rec.width / 2) + radius));
	}
}

bool Player::isGrounded()
{
	for (int x = 0; x < platforms->size(); ++x)
	{
		if (CheckCollisionCircleRec(position, radius +(grav*GetFrameTime()), (*platforms)[x].rec))
		{
			Vec2 boxCenter = Vec2((*platforms)[x].rec.x + ((*platforms)[x].rec.width / 2), (*platforms)[x].rec.y + ((*platforms)[x].rec.height / 2));
			float angle = Vec2(0, -1).AngleBetween(position - boxCenter);

			if (angle > Vec2(0, -1).AngleBetween(Vec2((*platforms)[x].rec.x, (*platforms)[x].rec.y) - boxCenter))
				continue;

			return true;
		}
	}

	return false;
}