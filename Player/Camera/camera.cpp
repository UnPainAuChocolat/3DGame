#include "../player.hpp"

Vector2  lookRotation = {0.0f, 0.0f};
Vector2  mouseDelta;
Vector3  yam;
Vector3  up = (Vector3){0.0f, 1.0f, 0.0f};

void  Player::CameraUpdate(Camera3D *camera)
{
  camera->position = (Vector3Add(position, (Vector3){0.0f, 1.5f, 0.0f}));
  mouseDelta = GetMouseDelta();

  lookRotation.x -= mouseDelta.x * sensibility;
  lookRotation.y -= mouseDelta.y * sensibility;

  if (lookRotation.y > 90.0f)
    lookRotation.y = 90.0f;
  if (lookRotation.y < -90.0f)
    lookRotation.y = -90.0f;

  direction = {0.0f, 0.0f, 1.0f};

  Vector3 axeHorizontal = {1.0f, 0.0f, 0.0f};
  direction = Vector3RotateByAxisAngle(direction, axeHorizontal, -(lookRotation.y) * DEG2RAD);

  direction = Vector3RotateByAxisAngle(direction, up, lookRotation.x * DEG2RAD);

  camera->target = Vector3Add(camera->position, direction);
}
