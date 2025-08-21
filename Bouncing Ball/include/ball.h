#pragma once
#include <raylib.h>

class Ball {
    private:
    Vector2 position;
    Vector2 speed;
    int radius;

    public:
    Ball();
    void update();
    void draw() const;
    void debugOverlay(const Vector2& position, const Vector2& speed, int radius);
    Vector2 getPosition() const;
    int getRadius() const;
    Vector2 getSpeed() const;
};