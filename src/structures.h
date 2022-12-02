#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "./utils.h"

typedef struct {
	int x;
	int y;
} strSpeed;

typedef struct {
	double x;
	double y;
} strPos;

class Bullet {
	public:
		int radius;
		strSpeed speed;
		strPos position;

		Bullet(int speedX=300, int speedY=300){
			radius = 6;
			position.x = centerX();
			position.y = centerY();
			speed.x = speedX;
			speed.y = speedY;
		}

		void bulletChangeSpeed(Bullet *bullet);
		void drawBullet(void);
};

class Player {
	public:
		strPos position;
		int width;
		int height;
		int side;
		int speed;

		Player(int playerSide, int playerSpeed){
			width = 10;
			height = 100;
			side = playerSide;
			speed = playerSpeed;

			switch (side){
				case 1: //esquerda
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

		void drawPlayer(void);
		void handlePlayerMovement(void);
};

#endif // !STRUCTURES_H
