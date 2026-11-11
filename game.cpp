#include "game.hpp"
#include "raymath.h"

void GameState::Initialize(){
  //Camera Initialize
  camera.position = (Vector3Add(player.position, (Vector3){0.0f, 1.5f, 0.0f}));
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  //Player Initialize
  player.position = (Vector3){0.0f, 0.5f, 0.0f};
  player.speed = 8.f;
  player.sensibility = 0.05f;
}

void GameState::Update(float deltaTime){
  player.Update(deltaTime, &camera);
}

void GameState::Draw(){
  ClearBackground(BLACK);
}
