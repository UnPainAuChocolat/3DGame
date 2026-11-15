#include "player.hpp"

Vector2  lookRotation = {0.0f, 0.0f};

void  Player::CameraUpdate()
{
  Vector3  up = (Vector3){0.0f, 1.0f, 0.0f};

  first_person_camera.position = (Vector3Add(position, (Vector3){0.0f, 1.5f, 0.0f}));
  Vector2 mouseDelta = GetMouseDelta();

  lookRotation.x -= mouseDelta.x * sensibility;
  lookRotation.y -= mouseDelta.y * sensibility;

  if (lookRotation.y > 90.0f)
    lookRotation.y = 90.0f;
  if (lookRotation.y < -90.0f)
    lookRotation.y = -90.0f;

  forward = {0.0f, 0.0f, 1.0f};

  Vector3 axeHorizontal = {1.0f, 0.0f, 0.0f};
  forward = Vector3RotateByAxisAngle(forward, axeHorizontal, -(lookRotation.y) * DEG2RAD);

  forward = Vector3RotateByAxisAngle(forward, up, lookRotation.x * DEG2RAD);

  first_person_camera.target = Vector3Add(first_person_camera.position, forward);

  HandleCameraTilting();
}

void  Player::HandleCameraTilting(){
  //manage camera tilting
  float maxTilt = 0.02f;

  float targetRoll = input_side * maxTilt;

  Vector3 baseUp = (Vector3){0.0f, 1.0f, 0.0f};

  first_person_camera.up = Vector3Lerp(first_person_camera.up, Vector3Add(
        baseUp, 
        Vector3Scale(right, targetRoll)), 5.f * delta_time
      );

  //manage camera forward anim
  float maxFov = 2.5f;

  float targetFov = (input_forward * maxFov) + fov;

  first_person_camera.fovy = Lerp(first_person_camera.fovy, targetFov, 10.f * delta_time);
}
