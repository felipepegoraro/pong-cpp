#ifndef BULLET_H
#define BULLET_H

#include "./utils.h"
#include <raylib.h>
#include <iostream>

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

#endif // !BULLET_H
