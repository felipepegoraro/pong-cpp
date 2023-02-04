#include "./src/utils.h"
#include "./src/structures.h"
#include <iostream>

/*
 * Felipe Pegoraro, 1|2/12/2022
 * Joguinho feito em C++
*/ 

int main(void)
{
	InitWindow(WIDTH, HEIGHT, NAME);
	SetWindowState(FLAG_VSYNC_HINT);

  Game game;

	while (!WindowShouldClose())
	{
		game.bullet.BulletChangeSpeed();
    game.ResetGame();
		BeginDrawing();

      game.DrawGame();
      game.HandleMoviment();
      game.HandleColision();
			game.bullet.HandleWinner(&game.score, &game.bullet);
      game.HandleBorderColision();

		EndDrawing();
	}

	CloseWindow();
	return(EXIT_SUCCESS);
}
