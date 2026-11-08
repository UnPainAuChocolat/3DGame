#include "raylib.h"

struct Player{
  Vector3 position;
  float speed;
};

struct GameState{
  Camera3D camera;
  Player player;

  void Initialize(){

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

  void Update(float deltaTime){
    if (IsKeyDown(KEY_W))
      player.position.z -= player.speed * deltaTime;
    if (IsKeyDown(KEY_S))
      player.position.z += player.speed * deltaTime;
    if (IsKeyDown(KEY_A))
      player.position.x -= player.speed * deltaTime;
    if (IsKeyDown(KEY_D))
      player.position.x += player.speed * deltaTime;

    camera.target = player.position;
  }

  void Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode3D(camera);
    DrawCube(player.position, 1.0f, 1.0f, 1.0f, RED);
    EndMode3D();
    EndDrawing();
  }
};
