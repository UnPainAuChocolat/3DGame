#include "raylib.h"
#include "Player/player.hpp"

class GameState{
  public:
    Camera3D  camera;
    Player    player;
    Shader    shader;

    int       lightColorLoc;
    int       objectsColorLoc;

    void      Initialize();
    void      Update(float deltaTime);
    void      Draw();
};
