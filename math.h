#ifndef HLAM_MATH_H
#define HLAM_MATH_H

namespace hlam {
typedef union Vec2 {
  struct {
    float x, y;
  };
  #ifdef RAYLIB_H
  Vector2 rl;
  #endif // RAYLIB_H
  float e[2];
} Vec2;

typedef union Vec3 {
  struct {
    float x, y, z;
  };
  struct {
    float r, g, b;
  };
  Vec2 xy;
  float e[3];
  #ifdef RAYLIB_H
  Vector3 rl;
  #endif // RAYLIB_H
} Vec3;

typedef union Rect {
  struct {
    float x, y, w, h;
  };
  struct {
    Vec2 pos;
    Vec2 size;
  };
  float e[4];
  #ifdef RAYLIB_H
  Rectangle rl;
  #endif // RAYLIB_H
} Rect;

inline bool operator==(Vec2 a, Vec2 b) { return (a.x == b.x) && (a.y == b.y); }
inline bool operator!=(Vec2 a, Vec2 b) { return !operator==(a, b); }

inline Vec2 operator+(Vec2 a) { return a; }
inline Vec2 operator-(Vec2 a) { return {-a.x, -a.y}; }

inline Vec2 operator+(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
inline Vec2 operator-(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }

inline Vec2 operator*(Vec2 a, float scalar) { return {a.x * scalar, a.y * scalar}; }
inline Vec2 operator*(float scalar, Vec2 a) { return operator*(a, scalar); }

inline Vec2 operator/(Vec2 a, float scalar) { return operator*(a, 1.0f / scalar); }

/* Hadamard Product */
inline Vec2 operator*(Vec2 a, Vec2 b) { return {a.x * b.x, a.y * b.y}; }
inline Vec2 operator/(Vec2 a, Vec2 b) { return {a.x / b.x, a.y / b.y}; }

inline Vec2 &operator+=(Vec2 &a, Vec2 b) { return (a = a + b); }
inline Vec2 &operator-=(Vec2 &a, Vec2 b) { return (a = a - b); }
inline Vec2 &operator*=(Vec2 &a, float scalar) { return (a = a * scalar); }
inline Vec2 &operator/=(Vec2 &a, float scalar) { return (a = a / scalar); }

inline bool operator==(Vec3 a, Vec3 b) { return (a.x == b.x) && (a.y == b.y) && (a.z == b.z); }
inline bool operator!=(Vec3 a, Vec3 b) { return !operator==(a, b); }

inline Vec3 operator+(Vec3 a) { return a; }
inline Vec3 operator-(Vec3 a) { return {-a.x, -a.y, -a.z}; }

inline Vec3 operator+(Vec3 a, Vec3 b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
inline Vec3 operator-(Vec3 a, Vec3 b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }

inline Vec3 operator*(Vec3 a, float scalar) { return {a.x * scalar, a.y * scalar, a.z * scalar}; }
inline Vec3 operator*(float scalar, Vec3 a) { return operator*(a, scalar); }

inline Vec3 operator/(Vec3 a, float scalar) { return operator*(a, 1.0f / scalar); }

/* Hadamard Product */
inline Vec3 operator*(Vec3 a, Vec3 b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
inline Vec3 operator/(Vec3 a, Vec3 b) { return {a.x / b.x, a.y / b.y, a.z / b.z}; }

inline Vec3 &operator+=(Vec3 &a, Vec3 b) { return (a = a + b); }
inline Vec3 &operator-=(Vec3 &a, Vec3 b) { return (a = a - b); }
inline Vec3 &operator*=(Vec3 &a, float scalar) { return (a = a * scalar); }
inline Vec3 &operator/=(Vec3 &a, float scalar) { return (a = a / scalar); }

inline float vec_dot(const Vec2 &v0, const Vec2 &v1) { return v0.x * v1.x + v0.y * v1.y; }
inline float vec_dot(const Vec3 &v0, const Vec3 &v1) { return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z; }

inline float vec_cross(const Vec2 &v0, const Vec2 &v1) { return v0.x * v1.y - v1.x * v0.y; }
inline Vec3 vec_cross(const Vec3 &v0, const Vec3 &v1) {
  return {
      v0.y * v1.z - v0.z * v1.y,
      v0.z * v1.x - v0.x * v1.z,
      v0.x * v1.y - v0.y * v1.x,
  };
}

}  // namespace hlam

#endif /* HLAM_MATH_H */

#ifdef HLAM_MATH_IMPLEMENTATION

namespace hlam {}  // namespace hlam

#endif /* HLAM_MATH_IMPLEMENTATION */