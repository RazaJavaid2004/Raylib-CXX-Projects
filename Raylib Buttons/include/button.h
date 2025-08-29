#pragma once

#include <raylib.h>

class Button {
    private:
        Texture2D button;
        Vector2 position;

    public:
        Button(const char* path, const Vector2& pos, float scale);
        ~Button();
        void draw();
        bool isClicked(const Vector2& mousePos, bool mousePressed); 
};