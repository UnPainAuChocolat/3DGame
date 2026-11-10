#include "player.hpp"

void Player::Update(float deltaTime, Camera3D *camera){
    if (IsKeyDown(KEY_W))
      position.z -= (speed * deltaTime) + direction.z;
    if (IsKeyDown(KEY_S))
      position.z += (speed * deltaTime) + direction.z;
    if (IsKeyDown(KEY_A))
      position.x -= (speed * deltaTime) + direction.x;
    if (IsKeyDown(KEY_D))
      position.x += (speed * deltaTime) + direction.x;

    CameraUpdate(camera);
}
