#ifndef SPE321_ROBOT_RAYLIBSRC_VEC2D_HPP
#define SPE321_ROBOT_RAYLIBSRC_VEC2D_HPP

#include "raylib.h"

struct Vec2D {
    double x, y; // reject float embrace double

    Vec2D(double x, double y) : x(x), y(y) {}

    // implicit cast operator to make this look like a raylib Vector2 when necessary
    operator Vector2() const; // NOLINT(*-explicit-constructor)
};

#endif // SPE321_ROBOT_RAYLIBSRC_VEC2D_HPP
