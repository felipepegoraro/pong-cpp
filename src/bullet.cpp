#include <iostream>
#include <raylib.h>
#include "./bullet.h"
#include "./utils.h"

void Bullet::BulletChangeSpeed(void)
{
	position.x += speed.x * GetFrameTime();
	position.y += speed.y * GetFrameTime();

	const int currentHeight = GetScreenHeight();

	if (position.y < 0)
	{
		position.y  =  0;
		speed.y    *= -1;
	}

	if (position.y > currentHeight)
	{
		position.y  = currentHeight;
		speed.y    *= -1;
	}
}

void Bullet::DrawBullet(void)
{
	DrawCircle(
		position.x,
		position.y,
		radius,
		WHITE
	);
}

void Bullet::HandleWinner(Score *sc, Bullet *bl)
{
  const int minWP = 3;

	if (position.x > WIDTH)
	{
		*bl = Bullet(300, 300);
		if (++(sc->match[0]) >= minWP && sc->match[0]-sc->match[1]>=2){
      sc->winner = "Left Player";
    }
	}

	if (position.x < 0)
	{
		*bl = Bullet(300, 300);
		if(++(sc->match[1]) >= minWP && sc->match[1]-sc->match[0]>=2){
      sc->winner = "Right Player";
    }
	}

	if (sc->winner) 
	{
		DrawText(TextFormat("%s Wins", sc->winner), 180, centerY()-15, 30, BLUE);
    bl->speed  = {0, 0};
		bl->radius = 0;
		return;
	}
}
