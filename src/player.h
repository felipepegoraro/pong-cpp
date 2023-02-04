#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <raylib.h>
#include "./utils.h"
#include "./bullet.h"

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

#endif // !PLAYER_H

