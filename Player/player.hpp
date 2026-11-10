#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"

//Player class
class Player{
  public:
    Vector3   position;
    Vector3   direction;
    float     sensibility;
    float     speed;

    void  Update(float deltaTime, Camera3D *camera);

    //Camera Handler
    void  CameraUpdate(Camera3D *camera);
};


#endif
