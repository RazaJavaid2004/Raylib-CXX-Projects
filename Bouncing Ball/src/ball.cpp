#include "ball.h"

Ball::Ball() : position({100.0f, 100.0f}), speed({5.0f, 5.0f}), radius(15) {}

void Ball::update() {
    position.x += speed.x;
    position.y += speed.y;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if((position.x + radius >= screenWidth) || (position.x - radius <= 0)) {
        speed.x *= -1;
    }

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

int Ball::getRadius() const {
    return radius;
}

Vector2 Ball::getSpeed() const {
    return speed;
}