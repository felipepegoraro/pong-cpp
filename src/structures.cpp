#include "./utils.h"
#include "./structures.h"
#include <iostream>
#include <raylib.h>

void Bullet::bulletChangeSpeed(void)
{
	position.x += speed.x * GetFrameTime();
	position.y += speed.y * GetFrameTime();

	const int currentHeight = GetScreenHeight();

	if (position.y < 0)
	{
		position.y = 0;
		speed.y *= -1;
	}

	if (position.y > currentHeight)
	{
		position.y = currentHeight;
		speed.y *= -1;
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

void Bullet::handleWinner(Score *sc, Bullet *bl)
{
	if (position.x > WIDTH)
	{
		*bl = Bullet(300, 300);
		if (++(sc->match[0]) == 3){
			sc->winner = "Left Player";
		}
	}

	if (position.x < 0)
	{
		*bl = Bullet(300, 300);
		if(++(sc->match[1]) == 3){
			sc->winner = "Right Player";
		}
	}

	if (sc->winner) 
	{
		DrawText(TextFormat("%s Wins", sc->winner), 180, centerY()-15, 30, BLUE);
		bl->speed.x = 0;
		bl->speed.y = 0;
		bl->radius = 0;
		return;
	}
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

void Player::handleBulletColision(Bullet *bullet)
{
	if (CheckCollisionCircleRec(
			Vector2{ (float)bullet->position.x, (float)bullet->position.y },
			bullet->radius,
			getRectangleFromPlayer()
		))
	{
		if (side == 1){
			if (bullet->speed.x < 0){
				bullet->speed.x *= -1.06;
				bullet->speed.y = (bullet->position.y - position.y)/(height/2) * bullet->speed.x;
			}
		}

		if (side == 2){
			if (bullet->speed.x > 0){
				bullet->speed.x *= -1.06;
				bullet->speed.y = (bullet->position.y - position.y)/(height/2) * -bullet->speed.x;
			}
		}
	}
}

void Player::handleBorderCollision(void)
{
	double pos[2] = {
		position.y - height/2,
		position.y + height/2
	};

	if (pos[0] <= 0.0f) 
		position.y = height/2;

	if (pos[1] >= GetScreenHeight())
		position.y = GetScreenHeight()-height/2;
}
