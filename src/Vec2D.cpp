//
// Created by hey-t on 2/5/2024.
//

#include "Vec2D.hpp"
Vec2D::operator Vector2() const {
    return Vector2(static_cast<float>(x), static_cast<float>(y));
}
