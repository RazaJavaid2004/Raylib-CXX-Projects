#pragma once

#include <raylib.h>
#include <iostream>

class Dino {
    private:
    Texture2D image;
    Vector2 position;
    int speed;

    public:
    Dino();
    ~Dino();
    void Update();
    void Draw();
    void DrawDebugOverlay(const Texture2D& image, const Vector2& position);
    bool IsColliding(const Rectangle& other) const;
    Rectangle GetBounds() const;
    Texture2D GetTexture() const;
    Vector2 GetPosition() const;
};