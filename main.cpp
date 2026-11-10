#include "game.hpp"

int main(){
  int WinWidth = 800;
  int WinHeight = 450;

  InitWindow(WinWidth, WinHeight, "3DGame");

  GameState game;
  World     world;
  game.Initialize();
  world.Load();

  SetTargetFPS(60);
  while (!WindowShouldClose()){
    float deltaTime = GetFrameTime();

    game.Update(deltaTime);
    game.Draw();
    world.Draw();
  }
  world.Unload();
  CloseWindow();
}
