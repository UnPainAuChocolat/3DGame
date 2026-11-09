#include "raylib.h"

struct Player{
  Vector3 position;
  float speed;
};

struct GameState{
  Camera3D camera;
  Player player;
  Shader shader;

  int lightColorLoc;
  int objectsColorLoc;

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

    //Shader Initialize
    shader = LoadShader(0, "Assets/light.glsl");
    lightColorLoc = GetShaderLocation(shader, "lightColor");
    objectsColorLoc = GetShaderLocation(shader, "objectsColor");
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
    ClearBackground(BLACK);

    BeginMode3D(camera);
    BeginShaderMode(shader);

    Vector3 lightColor = (Vector3){1.0f, 1.0f, 1.0f};
    Vector3 objectsColor = (Vector3){1.0f, 0.0f, 0.0f};

    SetShaderValue(shader, lightColorLoc, &lightColor, SHADER_UNIFORM_VEC3);
    SetShaderValue(shader, objectsColorLoc, &objectsColor, SHADER_UNIFORM_VEC3);

    DrawCube(player.position, 1.0f, 1.0f, 1.0f, RED);

    EndShaderMode();
    EndMode3D();
    EndDrawing();
  }
};
