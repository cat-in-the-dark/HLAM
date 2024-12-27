#include <iostream>

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
  std::cout << v.e[0] << " " << v.e[1] << std::endl;

  std::cout << vec_dot(v1, v2) << std::endl;

  return 0;
}