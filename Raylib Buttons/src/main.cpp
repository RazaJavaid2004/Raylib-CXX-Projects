#include "button.h"
#include <iostream>

int main() {
    // Initialize the window
    InitWindow(800, 600, "Raylib Button Example");
    SetTargetFPS(60);

    // Define Objects
    Texture2D background = LoadTexture("../assets/background/background.png");
    Button startButton("../assets/buttons/start_button.png", {300, 150}, 0.65);
    Button exitButton("../assets/buttons/exit_button.png", {300, 300}, 0.65);

    // Define Variables
    
    bool exit = false;

    // Main game loop
    while (!WindowShouldClose() && !exit) {
        // Event Handling
        Vector2 mousePos= GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        
        if(startButton.isClicked(mousePos, mousePressed)) {
            std::cout << "Start Button Pressed!" << std::endl;
        }

        if(exitButton.isClicked(mousePos, mousePressed)) {
            exit = true;
        }

        // Updating Movements

        // Drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        startButton.draw();
        exitButton.draw();

        EndDrawing();
    }

    // Unload resources
    UnloadTexture(background);
    CloseWindow();

    return 0;
}