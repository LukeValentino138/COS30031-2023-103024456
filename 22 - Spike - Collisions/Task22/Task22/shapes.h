#include <SDL.h>

class Shape {
public:
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    SDL_Rect rect;

    // Constructor for Rectangle
    Rectangle(SDL_Rect r) : rect(r) {}

    bool checkCollision(const Rectangle& other) const;
};

class Circle : public Shape {
public:
    SDL_Point center;
    int radius;

    // Constructor for Circle
    Circle(SDL_Point c, int r) : center(c), radius(r) {}

    bool checkCollision(const Circle& other) const;
};
