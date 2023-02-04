#include "./utils.h"
#include "./structures.h"
#include <iostream>
#include <raylib.h>

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

void Game::DrawGame(void){
  ClearBackground(BLACK);
  DrawFPS(15, 15);

  DrawText(
    TextFormat("%d x %d", score.match[0], score.match[1]),
    centerX()-40,
    15, 18,
    WHITE
  );

  DrawText(
    TextFormat("speed: %d", abs(bullet.speed.x)),
    WIDTH-110,
    15, 18,
    WHITE
  );

  bullet.DrawBullet();
  leftPlayer.DrawPlayer();
  rightPlayer.DrawPlayer();
}

void Game::ResetGame(void){
  if (IsKeyPressed(KEY_R)){
    bullet = Bullet(300, 300);
    leftPlayer = Player(1, 500);
    rightPlayer = Player(2, 500);
    score = { {0, 0}, nullptr };
  }
}

void Game::HandleMoviment(void)
{
  leftPlayer.HandlePlayerMovement();
  rightPlayer.HandlePlayerMovement();
}

void Game::HandleColision(){
  leftPlayer.HandleBulletColision(&bullet);
  rightPlayer.HandleBulletColision(&bullet);
}

void Game::HandleBorderColision(void){
  leftPlayer.HandleBorderCollision();
  rightPlayer.HandleBorderCollision();
}
