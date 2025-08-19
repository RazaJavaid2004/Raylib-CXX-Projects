#include "dino.h"

int main() {
    // Game Definitions

    // 1 - variables;

    // 2 - Window (must be before objects that load textures!);
    InitWindow(800, 600, "Dino Collision");
    if (!IsWindowReady()) {
        std::cerr << "Window failed to initialize!" << std::endl;
        system("pause"); // Pause to see the final output before closing
        return 1;
    }
    SetTargetFPS(60);
    
    // 3 - objects (safe to load textures now);
    Dino dino;
    Rectangle obstacle = Rectangle{500, 200, 0, 0};
    
    if (dino.GetTexture().id != 0) {
        obstacle.width = (float)dino.GetTexture().width;
        obstacle.height = (float)dino.GetTexture().height;
    } else {
        obstacle.width = 50.0f;
        obstacle.height = 50.0f;
    }

    bool showDebugOverlay = false;

    // Game Loop;
    std::cout << "Game started!" << std::endl;
    while(!WindowShouldClose()) {
        // 1 - event handling;
        if (IsKeyPressed(KEY_F1)) {
            showDebugOverlay = !showDebugOverlay;
        }

        // 2 - update positions;
        dino.Update();

        // 3- drawing;
        BeginDrawing();

        ClearBackground(WHITE);
        if(dino.IsColliding(obstacle)) {
            DrawRectangleLinesEx(dino.GetBounds(), 5, RED);
        }
        DrawRectangleLinesEx(obstacle, 5, BLACK);
        dino.Draw();
        if (showDebugOverlay) {
            dino.DrawDebugOverlay(dino.GetTexture(), dino.GetPosition());
        }
        EndDrawing();
    }
    std::cout << "Game ended!" << std::endl;
    CloseWindow();

    return 0;
}