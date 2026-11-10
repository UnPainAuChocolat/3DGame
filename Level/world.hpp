#ifndef WORLD_HPP
#define WORLD_HPP

#include "raylib.h"

class World{
  public:
    Model   model;
    Vector3 position;

    void    Load();
    void    Draw();
    void    Unload();
};

#endif
