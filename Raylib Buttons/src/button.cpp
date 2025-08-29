#include "button.h"

Button::Button(const char* path, const Vector2& pos, float scale) {
    Image image = LoadImage(path);
    if (image.data == nullptr) {
        TraceLog(LOG_ERROR, "Failed to load image from path: %s", path);
        return;
    }

    int originalWidth = image.width;
    int originalHeight = image.height;

    // Scale the image
    int newWidth = static_cast<int>(originalWidth * scale);
    int newHeight = static_cast<int>(originalHeight * scale);

    ImageResize(&image, newWidth, newHeight);

    button = LoadTextureFromImage(image);
    UnloadImage(image); // Unload the image after creating the texture
    position = pos;
}

Button::~Button() {
    UnloadTexture(button);
}

void Button::draw() {
    DrawTextureV(button, position, WHITE);
}

bool Button::isClicked(const Vector2& mousePos, bool mousePressed) {
    Rectangle buttonRect = {position.x, position.y, static_cast<float>(button.width), static_cast<float>(button.height)};

    if(CheckCollisionPointRec(mousePos, buttonRect) && mousePressed) {
        return true;
    }

    return false;
}