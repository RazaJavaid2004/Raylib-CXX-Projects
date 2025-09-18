#include "ball.h"

Ball::Ball(const Vector2& pos, const Vector2& sp, int r, Color c) : position(pos), speed(sp), radius(r), color(c) {}

void Ball::update() {
    position.x += speed.x;
    position.y += speed.y;

    const int screenHeight = GetScreenHeight();

    // Only check for top and bottom wall collisions
    if((position.y + radius >= screenHeight) || (position.y - radius <= 0)) {
        speed.y *= -1;
    }
}

void Ball::draw() const {
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::debugOverlay(const Vector2& position, const Vector2& speed, int radius) {
    int y = 10;
    int lineHeight = 20;
    
    DrawText("===Debug Overlay===", 10, y, 20, GREEN);
    y += lineHeight;
    
    DrawText(TextFormat("Position: (%.1f, %.1f)", position.x, position.y), 10, y, 20, DARKGRAY);
    y += lineHeight;
    
    DrawText(TextFormat("SpeedX: %.1f, SpeedY: %.1f", speed.x, speed.y), 10, y, 20, GREEN);
    y += lineHeight;
    
    DrawText(TextFormat("Radius: %d", getRadius()), 10, y, 20, BROWN);
    y += lineHeight;

    DrawText(TextFormat("FPS: %d", GetFPS()), 10, y, 20, RED);
    y += lineHeight;

    DrawText(TextFormat("Working Dir: %s", GetWorkingDirectory()), 10, y, 20, BLUE);
    y += lineHeight;
}

Vector2 Ball::getPosition() const {
    return position;
}

Vector2 Ball::getSpeed() const {
    return speed;
}

int Ball::getRadius() const {
    return radius;
}

float Ball::getPositionX() const {
    return position.x;
}

float Ball::getPositionY() const {
    return position.y;
}

float Ball::getSpeedX() const {
    return speed.x;
}

float Ball::getSpeedY() const {
    return speed.y;
}

void Ball::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Ball::setSpeedX(float spX) {
    speed.x = spX;
}

void Ball::setSpeedY(float spY) {
    speed.y = spY;
}