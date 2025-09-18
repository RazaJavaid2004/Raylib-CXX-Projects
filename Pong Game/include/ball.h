#pragma once
#include <raylib.h>

class Ball {
    private:
    Vector2 position;
    Vector2 speed;
    int radius;
    Color color;

    public:
    Ball(const Vector2& pos, const Vector2& sp, int r, Color c);
    void update();
    void draw() const;
    void debugOverlay(const Vector2& position, const Vector2& speed, int radius);
    Vector2 getPosition() const;
    Vector2 getSpeed() const;
    int getRadius() const;
    float getPositionX() const;
    float getPositionY() const;
    float getSpeedX() const;
    float getSpeedY() const;
    void setPosition(float x, float y);
    void setSpeedX(float spX);
    void setSpeedY(float spY);
};