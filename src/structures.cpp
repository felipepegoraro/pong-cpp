#include "./utils.h"
#include "./structures.h"
#include <iostream>
#include <raylib.h>

void Bullet::bulletChangeSpeed(Bullet *bullet)
{
	bullet->position.x += bullet->speed.x * GetFrameTime();
	bullet->position.y += bullet->speed.y * GetFrameTime();

	const int currentWidth = GetScreenWidth();
	const int currentHeight = GetScreenHeight();

	if (bullet->position.y < 0)
	{
		bullet->position.y = 0;
		bullet->speed.y *= -1;
	}

	if (bullet->position.y > currentHeight)
	{
		bullet->position.y = currentHeight;
		bullet->speed.y *= -1;
	}

	if (bullet->position.x < 0)
	{
		bullet->position.x = 0;
		bullet->speed.x *= -1;
	}

	if (bullet->position.x > currentWidth)
	{
		bullet->position.x = currentWidth;
		bullet->speed.x *= -1;
	}
}

void Bullet::drawBullet(void)
{
	DrawCircle(
		position.x,
		position.y,
		radius,
		WHITE
	);
}

void Player::handlePlayerMovement(void)
{
	int keys[2] = { KEY_UP, KEY_DOWN };

	if (side == 1)
	{
		keys[0] = KEY_W;
		keys[1] = KEY_S;
	}

	if (IsKeyDown(keys[0]))
		position.y -= speed * GetFrameTime();

	if (IsKeyDown(keys[1]))
		position.y += speed * GetFrameTime();
}

Rectangle Player::getRectangleFromPlayer()
{
	return Rectangle { 
		(float) position.x - width/2,
		(float) position.y - height/2,
		(float) width,
		(float) height 
	};
}

void Player::drawPlayer(void)
{
	DrawRectangleRec(
		getRectangleFromPlayer(),
		WHITE
	);
}

void Player::hangleBulletColision(Bullet *bullet)
{
	if (CheckCollisionCircleRec(
			Vector2{ (float)bullet->position.x, (float)bullet->position.y },
			bullet->radius,
			getRectangleFromPlayer()
		)
	) {
		bullet->speed.x *= -1;
	}
}
