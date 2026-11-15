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
  Player player((Vector3){0.f, 0.f, 0.f}, 0.04f, 45.f);

  SetTargetFPS(60);
  while (!WindowShouldClose()){
    float deltaTime = GetFrameTime();
    BeginDrawing();
      BeginMode3D(player.first_person_camera);
        player.Update(deltaTime);
        game.Draw();
        world.Draw();
      EndMode3D();
    EndDrawing();
  }
  EnableCursor();
  world.Unload();
  CloseWindow();
}
