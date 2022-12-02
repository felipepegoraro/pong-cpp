#include <iostream>
#include <raylib.h>
#include "./src/utils.h"
#include "./src/structures.h"

#define  WIDTH 600
#define HEIGHT 400
#define   NAME "Pong"

int main(void)
{
	InitWindow(WIDTH, HEIGHT, NAME);
	SetWindowState(FLAG_VSYNC_HINT);


	Bullet bullet(300, 300);
	Player leftPlayer(1, 250);
	Player rightPlayer(2, 250);

	while (!WindowShouldClose())
	{
		bullet.bulletChangeSpeed(&bullet);
		BeginDrawing();

			ClearBackground(BLACK);
			DrawFPS(15, 15);

			bullet.drawBullet();
			leftPlayer.drawPlayer();
			rightPlayer.drawPlayer();

			leftPlayer.handlePlayerMovement();
			rightPlayer.handlePlayerMovement();

		EndDrawing();
	}

	CloseWindow();
	return(EXIT_SUCCESS);
}
