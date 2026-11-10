#include "world.hpp"

void  World::Load(){
  model = LoadModel("../Assets/Objects/grassGround.glb");
  position = (Vector3){0.0f, 0.0f, 0.0f};
}

void  World::Draw(){
  DrawModel(model, position, 1.0f, WHITE);
}

void  World::Unload(){
  UnloadModel(model);
}
