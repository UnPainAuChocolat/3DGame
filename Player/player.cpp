#include "player.hpp"

void Player::Update(float deltaTime)
{
    if (IsKeyDown(KEY_W))
      position.z -= speed * deltaTime;
    if (IsKeyDown(KEY_S))
      position.z += speed * deltaTime;
    if (IsKeyDown(KEY_A))
      position.x -= speed * deltaTime;
    if (IsKeyDown(KEY_D))
      position.x += speed * deltaTime;
}
