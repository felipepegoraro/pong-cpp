#include <iostream>
#include <raylib.h>
#include "./src/utils.h"
#include "./src/structures.h"

int main(void)
{
	InitWindow(WIDTH, HEIGHT, NAME);
	SetWindowState(FLAG_VSYNC_HINT);

	Score score = { {0, 0}, nullptr };
	Bullet bullet(300, 300);
	Player leftPlayer(1, 500);
	Player rightPlayer(2, 500);

	while (!WindowShouldClose())
	{
		bullet.bulletChangeSpeed();

		if (IsKeyPressed(KEY_R)){
			bullet = Bullet(300, 300);
			leftPlayer = Player(1, 500);
			rightPlayer = Player(2, 500);
			score = { {0, 0}, nullptr };
		}

		BeginDrawing();

			ClearBackground(BLACK);
			DrawFPS(15, 15);
			DrawText(TextFormat("%d x %d", score.match[0], score.match[1]), centerX()-40, 15, 18, WHITE);
			DrawText(TextFormat("speed: %d", abs(bullet.speed.x)), WIDTH-110, 15, 18, WHITE);

			bullet.drawBullet();
			leftPlayer.drawPlayer();
			rightPlayer.drawPlayer();

			leftPlayer.handlePlayerMovement();
			rightPlayer.handlePlayerMovement();

			leftPlayer.handleBulletColision(&bullet);
			rightPlayer.handleBulletColision(&bullet);

			bullet.handleWinner(&score, &bullet);

			leftPlayer.handleBorderCollision();
			rightPlayer.handleBorderCollision();

		EndDrawing();
	}

	CloseWindow();
	return(EXIT_SUCCESS);
}
