#include "player.hpp"

Vector3 plane = (Vector3){1.0f, 0.0f, 1.0f};

void Player::Update(float deltaTime, Camera3D *camera){
  float input_forward = 0.0f;
  float input_side = 0.0f;

  if (IsKeyDown(KEY_W)) input_forward += 1.0f;
  if (IsKeyDown(KEY_S)) input_forward -= 1.0f;
  if (IsKeyDown(KEY_A)) input_side -= 1.0f;
  if (IsKeyDown(KEY_D)) input_side += 1.0f;

  Vector3 right = Vector3CrossProduct(forward, (Vector3){0.0f, 1.0f, 0.0f});

  Vector3 moveDir = Vector3Add(
      Vector3Scale(forward, input_forward),
      Vector3Scale(right, input_side)
      );

  if (Vector3Length(moveDir) > 0.0f)
  {
    moveDir = Vector3Normalize(moveDir);
  }

  moveDir = Vector3Multiply(moveDir, plane);

  moveDir = Vector3Scale(moveDir, speed * deltaTime);
  position = Vector3Add(position, moveDir);

  float maxTilt = 0.04f;

  float targetPitch = input_forward * maxTilt;
  float targetRoll = input_side * maxTilt;

  CameraUpdate(camera);

  Vector3 baseUp = (Vector3){0.0f, 1.0f, 0.0f};
  Vector3 tiltOffset = Vector3Add(
      Vector3Scale(right, targetRoll),
      Vector3Scale(forward, targetPitch)
  );
  
  camera->up = Vector3Normalize(Vector3Add(baseUp, tiltOffset));
}
