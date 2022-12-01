#include <iostream>
#include <raylib.h>

#define  WIDTH 600
#define HEIGHT 400
#define   NAME "Pong"

using namespace std;

double centerX(void);
double centerY(void);

int main(void)
{
	InitWindow(WIDTH, HEIGHT, NAME);
	SetWindowState(FLAG_VSYNC_HINT);

	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(15, 15);

			DrawCircle(centerX(), centerY(), 10, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return(EXIT_SUCCESS);
}

double centerX(void)
{
	return (double) GetScreenWidth()/2;
}

double centerY(void)
{
	return (double) GetScreenHeight()/2;
}
