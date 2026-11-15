#include "player.hpp"

Vector3 plane = (Vector3){1.0f, 0.0f, 1.0f};

Player::Player(Vector3 base_position, float base_sensibility, float base_fov){
  position = base_position;
  sensibility = base_sensibility;
  fov = base_fov;

  //Camera Initialize
  first_person_camera.position = (Vector3Add(position, (Vector3){0.0f, 1.5f, 0.0f}));
  first_person_camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  first_person_camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  first_person_camera.fovy = 45.0f;
  first_person_camera.projection = CAMERA_PERSPECTIVE;
}

void Player::Update(float deltaTime){
  delta_time = deltaTime;
  input_forward = 0.0f;
  input_side = 0.0f;
  speed = 4.f;

  if (IsKeyDown(KEY_W)) input_forward += 1.0f;
  if (IsKeyDown(KEY_S)) input_forward -= 1.0f;
  if (IsKeyDown(KEY_A)) input_side -= 1.0f;
  if (IsKeyDown(KEY_D)) input_side += 1.0f;

  right = Vector3CrossProduct(forward, (Vector3){0.0f, 1.0f, 0.0f});

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

  CameraUpdate();
}
