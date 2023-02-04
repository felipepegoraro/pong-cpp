#include "./game.h"

void Game::DrawGame(void){
  ClearBackground(BLACK);
  DrawFPS(15, 15);

  DrawText(
    TextFormat("%d x %d", score.match[0], score.match[1]),
    centerX()-40,
    15, 18,
    WHITE
  );

  DrawText(
    TextFormat("speed: %d", abs(bullet.speed.x)),
    WIDTH-110,
    15, 18,
    WHITE
  );

  bullet.DrawBullet();
  leftPlayer.DrawPlayer();
  rightPlayer.DrawPlayer();
}

void Game::ResetGame(void){
  if (IsKeyPressed(KEY_R)){
    bullet = Bullet(300, 300);
    leftPlayer = Player(1, 500);
    rightPlayer = Player(2, 500);
    score = { {0, 0}, nullptr };
  }
}

void Game::HandleMoviment(void)
{
  leftPlayer.HandlePlayerMovement();
  rightPlayer.HandlePlayerMovement();
}

void Game::HandleColision(){
  leftPlayer.HandleBulletColision(&bullet);
  rightPlayer.HandleBulletColision(&bullet);
}

void Game::HandleBorderColision(void){
  leftPlayer.HandleBorderCollision();
  rightPlayer.HandleBorderCollision();
}
