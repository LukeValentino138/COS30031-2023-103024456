#include "shapes.h"
#include <cmath>

bool Rectangle::checkCollision(const Rectangle& other) const {
    if (rect.y + rect.h <= other.rect.y) return false;
    if (rect.y >= other.rect.y + other.rect.h) return false;
    if (rect.x + rect.w <= other.rect.x) return false;
    if (rect.x >= other.rect.x + other.rect.w) return false;
    return true;
}

bool Circle::checkCollision(const Circle& other) const {
    int dx = center.x - other.center.x;
    int dy = center.y - other.center.y;
    int distance = std::sqrt(dx * dx + dy * dy);
    return distance < (radius + other.radius);
}
