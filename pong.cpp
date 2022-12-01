#include <iostream>
#include <raylib.h>
#include "./src/utils.h"
#include "./src/structures.h"

#define  WIDTH 600
#define HEIGHT 400
#define   NAME "Pong"

using namespace std;

int main(void)
{
	InitWindow(WIDTH, HEIGHT, NAME);
	SetWindowState(FLAG_VSYNC_HINT);

	const int rHeight = 100;

	/* bullet *bullet = new ::bullet; */
	Bullet bullet;
	bullet.bulletInicialization(&bullet);

	while (!WindowShouldClose())
	{

		bullet.bulletChangeSpeed(&bullet, 300, 300);

		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(15, 15);
			DrawCircle(
				bullet.position.x,
				bullet.position.y,
				bullet.radius,
				WHITE
			);

			DrawRectangle(17, centerY()-rHeight/2, 10, rHeight, WHITE);
			DrawRectangle(WIDTH-25, centerY()-rHeight/2, 10, rHeight, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return(EXIT_SUCCESS);
}
