#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"
#include <cstdio>

//Player class
class Player{
  public:
    Camera    first_person_camera;
    Vector3   position;
    Vector3   forward;
    float     sensibility;
    float     speed;
    float     fov;

    void  Update(float deltaTime);
    Player(Vector3 position, float sensibility, float fov);

    //Camera Handler
    void  CameraUpdate();

  private:
    Vector3 right;
    float   delta_time;
    float   input_side;
    float   input_forward;

    void  HandleCameraTilting();
};


#endif
