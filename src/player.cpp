#include "./player.h"

void Player::HandlePlayerMovement(void)
{
  Point<int> keys = { KEY_UP, KEY_DOWN };

  if (side == 1)
	{
		keys.x = KEY_W;
		keys.y = KEY_S;
	}

  if (IsKeyDown(keys.x))
    position.y -= speed * GetFrameTime();

  if (IsKeyDown(keys.y))
    position.y += speed * GetFrameTime();
}

Rectangle Player::GetRectangleFromPlayer()
{
	return Rectangle { 
		(float) position.x -  width/2,
		(float) position.y - height/2,
		(float) width,
		(float) height 
	};
}

void Player::DrawPlayer(void)
{
	DrawRectangleRec(
		GetRectangleFromPlayer(),
		WHITE
	);
}

void Player::HandleBulletColision(Bullet *bullet)
{
  const double upSpeed  =  1.16;
  const double maxSpeed = 550.0;

	if (CheckCollisionCircleRec(
			Vector2{ (float)bullet->position.x, (float)bullet->position.y },
			bullet->radius,
			GetRectangleFromPlayer()
		))
	{
		if (side == 1){
			if (bullet->speed.x < 0){
				bullet->speed.x *= (bullet->speed.x > maxSpeed) ? -upSpeed : -1;
				bullet->speed.y  = (bullet->position.y - position.y)/(height/2) * bullet->speed.x;
			}
		}

		if (side == 2){
			if (bullet->speed.x > 0){
				bullet->speed.x *= (bullet->speed.x > maxSpeed) ? -1 : -upSpeed;
				bullet->speed.y  = (bullet->position.y - position.y)/(height/2) * -bullet->speed.x;
			}
		}
	}
}

void Player::HandleBorderCollision(void)
{
  const int scHeight = GetScreenHeight();

	double pos[2] = {
		position.y - height/2,
		position.y + height/2
	};

	if (pos[0] <= 0.0f) 
		position.y = height/2;

	if (pos[1] >= scHeight)
		position.y = scHeight-height/2;
}
