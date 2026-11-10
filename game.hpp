#include "raylib.h"
#include "Player/player.hpp"
#include "Level/world.hpp"

class GameState{
  public:
    Camera3D  camera;
    Player    player;
    Shader    shader;

    void      Initialize();
    void      Update(float deltaTime);
    void      Draw();
};
