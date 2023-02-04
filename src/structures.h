#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "./utils.h"
#include <raylib.h>
#include <iostream>

struct Score {
	int match[2];
	const char *winner;
};

template <typename T>
struct Point { 
  T x;
  T y; 
};

class Bullet {
	public:
		int radius;
		Point<int> speed;
		Point<double> position;

		Bullet(int speedX=300, int speedY=300){
			radius     = 6;
			position.x = centerX();
			position.y = centerY();
			speed.x    = speedX;
			speed.y    = speedY;
		}

		void BulletChangeSpeed(void);
		void DrawBullet(void);
		void HandleWinner(Score *, Bullet *);
};

class Player {
	public:
		Point<double> position;
		int width;
		int height;
		int side;
		int speed;

		Player(int playerSide, int playerSpeed){
			width  = 10;
			height = 100;
			side   = playerSide;
			speed  = playerSpeed;

			switch (side){
				case 1: // esquerda
					position.x = 17;
					position.y = centerY()-height/2;
					break;
				case 2: // direita
					position.x = GetScreenWidth()-25;
					position.y = centerY()-height/2;
					break;
				default:
					break;
			}
		}

		void DrawPlayer(void);
		void HandlePlayerMovement(void);
		Rectangle GetRectangleFromPlayer(void);
		void HandleBulletColision(Bullet *bullet);
		void HandleBorderCollision(void);
};

class Game {
  private:
    Player leftPlayer;
    Player rightPlayer;

  public:
    Game() : leftPlayer(1, 500), rightPlayer(2, 500), bullet(300, 300) {}
    Bullet bullet;
    Score score = { {0, 0}, nullptr };

    void DrawGame(void);
    void ResetGame(void);
    void HandleMoviment(void);
    void HandleColision(void);
    void HandleBorderColision(void);
};

#endif // !STRUCTURES_H
