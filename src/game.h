#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <iostream>
#include "./utils.h"
#include "./player.h"
#include "./bullet.h"

class Game {
  private:
    Player leftPlayer;
    Player rightPlayer;

  public:
    Game() : leftPlayer(1, 500), rightPlayer(2, 500), bullet(300, 300) {}
    Bullet bullet;
    Score score = { {0, 0}, nullptr };

    void DrawGame(void);
    void ResetGame(void);
    void HandleMoviment(void);
    void HandleColision(void);
    void HandleBorderColision(void);
};

#endif // !GAME_H
