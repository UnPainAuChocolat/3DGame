#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

class Player{
  public:
    Vector3 position;
    int     speed;

    void  Update(float deltaTime);
};

#endif
