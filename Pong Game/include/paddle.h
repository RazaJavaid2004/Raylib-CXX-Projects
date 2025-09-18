#pragma once
#include <raylib.h>
#include "ball.h"

class Paddle {
    protected:
        int posX;
        int posY;
        int width;
        int height;
        int speedX;
        int speedY;
        Color color;
        void LimitMovement();
    public:
        Paddle(int x, int y, int _width, int _height, int spX, int spY, Color c);
        void draw() const;
        void update();
        Rectangle getRect() const;
};

class CPUPaddle : public Paddle {
    private:
        float targetY;           // Target Y position with prediction error
        int reactionDelay;       // Frames to wait before responding
        int frameCounter;        // Current frame count
        float difficultyFactor;  // How accurate the AI is (0.0 to 1.0)
        
    public:
        CPUPaddle(int x, int y, int _width, int _height, int spX, int spY, Color c);
        void update(Ball& ball);
        Rectangle getRect() const;
        void updateTargetPosition(Ball& ball);
};