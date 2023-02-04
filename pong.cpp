#include "./src/game.h"

/*
 * Felipe Pegoraro, 1|2/12/2022
 * joguinho feito em C++
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
