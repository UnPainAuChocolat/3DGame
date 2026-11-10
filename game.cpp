#include "game.hpp"
#include "raymath.h"

void GameState::Initialize(){
  //Camera Initialize
  camera.position = (Vector3){0.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  //Player Initialize
  player.position = (Vector3){0.0f, 0.5f, 0.0f};
  player.speed = 4.0f;
}

void GameState::Update(float deltaTime){
  player.Update(deltaTime);
  camera.target = player.position;
}

void GameState::Draw(){
  BeginDrawing();
  ClearBackground(BLACK);

  BeginMode3D(camera);

  DrawCube(player.position, 1.0f, 1.0f, 1.0f, RED);

  EndMode3D();
  EndDrawing();
}
