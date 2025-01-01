#include <iostream>
#include "raylib.h"

#define HLAM_MATH_IMPLEMENTATION
#include "math.h"

int main() {
  std::cout << "AAA" << std::endl;

  hlam::Vec2 v1{1, 2};
  hlam::Vec2 v2{2, 3};

  auto v = v1 * v2;

  std::cout << v.x << " " << v.y << std::endl;
  v *= 3;

  std::cout << v.x << " " << v.y << std::endl;

  std::cout << vec_dot(v1, v2) << std::endl;

  InitWindow(400, 240, "Example");

  hlam::Vec2 p{20,10};
  hlam::Vec2 size{40,60};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(PINK);
    DrawRectangleV(p, size, GREEN);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
