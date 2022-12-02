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

void Player::drawPlayer(void)
{
	DrawRectangle(
		position.x,
		position.y,
		width,
		height,
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
