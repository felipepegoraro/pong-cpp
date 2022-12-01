#include "./utils.h"
#include "./structures.h"
#include <iostream>

void Bullet::bulletInicialization(Bullet *bullet)
{
	bullet->radius = 6;
	bullet->position.x = centerX();
	bullet->position.y = centerY();
}

void Bullet::bulletChangeSpeed(Bullet *bullet, double speedX, double speedY)
{
	bullet->position.x += speedX * GetFrameTime();
	bullet->position.y += speedY * GetFrameTime();
 

	if (bullet->position.y < 0)
	{
		std::cout << "[Y]: revertendo...\n";
		bullet->position.y = 0;
		bullet->speed.y *= -1;
	}

	// fim da tela... (revertendo)
	if (bullet->position.y > GetScreenHeight())
	{
		bullet->position.y = GetScreenHeight();
		bullet->position.y *= -1;
		std::cout << bullet->speed.y << std::endl; // FIXME!!!
	}
}
