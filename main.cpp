#include "game.hpp"

int main(){
  int WinWidth = 800;
  int WinHeight = 450;

  InitWindow(WinWidth, WinHeight, "3DGame");

  GameState game;
  World     world;
  DisableCursor();
  game.Initialize();
  world.Load();

  SetTargetFPS(60);
  while (!WindowShouldClose()){
    float deltaTime = GetFrameTime();
    BeginDrawing();
      BeginMode3D(game.camera);
        game.Update(deltaTime);
        game.Draw();
        world.Draw();
      EndMode3D();
    EndDrawing();
  }
  EnableCursor();
  world.Unload();
  CloseWindow();
}
