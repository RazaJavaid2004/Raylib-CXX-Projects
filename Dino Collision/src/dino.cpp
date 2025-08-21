#include "dino.h"

Dino::Dino() {
    image = LoadTexture("../assets/textures/dino.png");
    if(image.id == 0) {
        std::cerr << "Failed to load texture: ../assets/textures/dino.png" << std::endl;
    }
    position.x = 100.0f;
    position.y = 100.0f;
    speed = 10;
}

Dino::~Dino() {
    UnloadTexture(image);
}

void Dino::Update() {
    if(IsKeyDown(KEY_LEFT)) position.x -= speed;
    if(IsKeyDown(KEY_RIGHT)) position.x += speed;
    if(IsKeyDown(KEY_UP)) position.y -= speed;
    if(IsKeyDown(KEY_DOWN)) position.y += speed;
}

void Dino::Draw() {
    if (image.id != 0) {
        DrawTextureV(image, position, WHITE);
    } else {
        DrawRectangleV(position, (Vector2){50, 50}, BLUE);
    }
}

void Dino::DrawDebugOverlay(const Texture2D& image, const Vector2& position) {
    int y = 10;
    int lineHeight = 20;

    DrawText("=== DEBUG OVERLAY ===", 10, y, 20, GREEN); y += lineHeight;

    if (image.id == 0) {
        DrawText("Texture: NOT LOADED", 10, y, 20, RED);
    } else {
        DrawText(TextFormat("Texture ID: %u", image.id), 10, y, 20, DARKGREEN);
        DrawText(TextFormat("Texture Size: %dx%d", image.width, image.height), 10, y + lineHeight, 20, SKYBLUE);
        y += 2 * lineHeight;
    }

    DrawText(TextFormat("Position: (%.1f, %.1f)", position.x, position.y), 10, y, 20, LIGHTGRAY); y += lineHeight;
    DrawText(TextFormat("FPS: %d", GetFPS()), 10, y, 20, YELLOW); y += lineHeight;
    DrawText(TextFormat("Working Dir: %s", GetWorkingDirectory()), 10, y, 20, GRAY); y += lineHeight;
}

bool Dino::IsColliding(const Rectangle& other) const {
    return CheckCollisionRecs(GetBounds(), other);
}

Rectangle Dino::GetBounds() const {
    return Rectangle{position.x, position.y, (float)image.width, (float)image.height};
}

Texture2D Dino::GetTexture() const {
    return image;
}

Vector2 Dino::GetPosition() const {
    return position;
}