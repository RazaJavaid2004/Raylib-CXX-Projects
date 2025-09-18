#include "paddle.h"

// CLass Paddle

void Paddle::LimitMovement() {
    if(posY <= 0) posY = 0;
    if(posY + height >= GetScreenHeight()) posY = GetScreenHeight() - height;
}

Paddle::Paddle(int x, int y, int _width, int _height, int spX, int spY, Color c) : posX(x), posY(y), width(_width), height(_height), speedX(spX), speedY(spY), color(c) {}

void Paddle::draw() const {
    DrawRectangle(posX, posY, width, height, color);
}

void Paddle::update() {
    if(IsKeyDown(KEY_UP)) posY -= speedY;
    if(IsKeyDown(KEY_DOWN)) posY += speedY;
    LimitMovement();
}

Rectangle Paddle::getRect() const {
    return Rectangle{static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)};
}

// Class CPU Paddle

CPUPaddle::CPUPaddle(int x, int y, int _width, int _height, int spX, int spY, Color c) 
    : Paddle(x, y, _width, _height, spX, spY, c) {
    targetY = y;
    reactionDelay = 10;         // Wait 10 frames before reacting
    frameCounter = 0;
    difficultyFactor = 0.85f;   // 85% accuracy
}

void CPUPaddle::updateTargetPosition(Ball& ball) {
    // Only predict if ball is moving towards the AI
    if (ball.getSpeedX() < 0) {
        // Calculate time for ball to reach paddle's X position
        float timeToReach = (posX - ball.getPositionX()) / ball.getSpeedX();
        
        // Predict Y position where ball will intersect
        float predictedY = ball.getPositionY() + (ball.getSpeedY() * timeToReach);
        
        // Add some random error to make AI imperfect
        float errorMargin = height * (1.0f - difficultyFactor);
        float randomError = GetRandomValue(-errorMargin, errorMargin);
        
        // Update target position with error
        targetY = predictedY - (height / 2) + randomError;
        
        // Keep target within screen bounds
        if (targetY < 0) targetY = 0;
        if (targetY + height > GetScreenHeight()) targetY = GetScreenHeight() - height;
    }
}

void CPUPaddle::update(Ball& ball) {
    frameCounter++;
    
    // Update target position every reactionDelay frames
    if (frameCounter >= reactionDelay) {
        frameCounter = 0;
        updateTargetPosition(ball);
    }
    
    // Move towards target position
    if (posY + height/2 < targetY + height/2) {
        posY += speedY;
    }
    if (posY + height/2 > targetY + height/2) {
        posY -= speedY;
    }
    
    LimitMovement();
}

Rectangle CPUPaddle::getRect() const {
    return Rectangle{static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(width), static_cast<float>(height)};
}