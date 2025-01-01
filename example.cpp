#include <iostream>

#include "raylib.h"

#define HLAM_MATH_IMPLEMENTATION
#include "math.h"

#define HLAM_COLLISIONS2D_IMPLEMENTATION
#include "collisions2D.h"

hlam::Rect r1{100, 20, 30, 30};
hlam::Rect r2{120, 40, 30, 30};
hlam::Vec2 line[2]{{150, 50}, {200, 100}};
hlam::Vec2 line2[2]{{150, 100}, {200, 180}};
hlam::Circle circle{{100, 100}, 30};
hlam::Triangle2 triangle{{130, 150}, {100, 150}, {110, 180}};

void CollisionDemo() {
  hlam::Vec2 ds{};
  if (IsKeyDown(KEY_UP)) {
    ds.y = -1;
  }
  if (IsKeyDown(KEY_DOWN)) {
    ds.y = 1;
  }
  if (IsKeyDown(KEY_LEFT)) {
    ds.x = -1;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    ds.x = 1;
  }

  r2.x += ds.x;
  r2.y += ds.y;
  circle.center += ds;

  DrawRectangle(r2.x, r2.y, r2.width, r2.height, BLUE);
  DrawCircleV(circle.center, circle.radius, RED);

  auto rectColor = BLUE;
  if (hlam::collision_rect_rect(r1, r2)) {
    rectColor = GREEN;
  }
  DrawRectangle(r1.x, r1.y, r1.width, r1.height, rectColor);

  auto lineColor = BLUE;
  if (hlam::collision_line_rect(line[0], line[1], r2)) {
    lineColor = GREEN;
  }
  DrawLineV(line[0], line[1], lineColor);

  auto triangleColor = RED;
  if (hlam::collision_triangle_circle(triangle, circle.center, circle.radius)) {
    triangleColor = GREEN;
  }
  DrawTriangle(triangle.p1, triangle.p2, triangle.p3, triangleColor);

  auto line2Color = RED;
  if (hlam::collision_line_circle(line2[0], line2[1], circle.center, circle.radius)) {
    line2Color = GREEN;
  }
  DrawLineV(line2[0], line2[1], line2Color);
}

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

  hlam::Vec2 p{20, 10};
  hlam::Vec2 size{40, 60};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(PINK);
    DrawRectangleV(p, size, GREEN);

    CollisionDemo();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
