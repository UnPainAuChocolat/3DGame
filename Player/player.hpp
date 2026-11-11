#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"
#include <cstdio>

//Player class
class Player{
  public:
    Vector3   position;
    Vector3   forward;
    float     sensibility;
    float     speed;

    void  Update(float deltaTime, Camera3D *camera);

    //Camera Handler
    void  CameraUpdate(Camera3D *camera);
};


#endif
