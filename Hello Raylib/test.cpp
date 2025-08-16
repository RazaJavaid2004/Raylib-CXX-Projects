#include <raylib.h>

int main() {
    InitWindow(800, 600, "raylib test");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 350, 280, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// Ctrl + Shift + B -> Build .exe File
// F5 -> Run .exe File