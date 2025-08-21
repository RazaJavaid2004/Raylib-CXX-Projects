#include "ball.h"

int main() {
    // game definitions;

    // 1- defining the variables needed;
    const Color darkGreen = {20, 160, 133, 255};    // r, g, b, transparency(255 -> Opaque);
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    bool showDebugOverlay = false;
    
    // 2- creating the game window;
    InitWindow(screenWidth, screenHeight, "Bouncing Ball");
    SetTargetFPS(60);

    // 3- defining the game objects;
    Ball ball;

    // game loop;
    
    while(!WindowShouldClose()) {
        // 1- event handling;
        if(IsKeyPressed(KEY_F1)) {
            showDebugOverlay = !showDebugOverlay;
        }

        // 2- updating positions
        ball.update();

        // 3- Drawing
        BeginDrawing();
        
        ClearBackground(darkGreen);
        ball.draw();
        if(showDebugOverlay) {
            ball.debugOverlay(ball.getPosition(), ball.getSpeed(), ball.getRadius());
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}