#ifndef GAME_HPP
#define GAME_HPP

#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include "Player/player.hpp"
#include "Level/world.hpp"

//GameState
class GameState{
  public:
    Camera3D  camera;
    Player    player;
    Shader    shader;

    void      Initialize();
    void      Update(float deltaTime);
    void      Draw();
};

#endif
