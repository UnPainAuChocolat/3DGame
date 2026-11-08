#include "game.hpp"

int main(){
  int WinWidth = 800;
  int WinHeight = 450;

  InitWindow(WinWidth, WinHeight, "3DGame");

  GameState game;
  game.Initialize();

  SetTargetFPS(60);
  while (!WindowShouldClose()){
    float deltaTime = GetFrameTime();

    game.Update(deltaTime);
    game.Draw();
  }
  CloseWindow();
}
