#pragma once
#include <raylib.h>

class Score {
    const char* text;
    int posX;
    int posY;
    int fontSize;
    public:
    Color color;
    Score(const char* t, int x, int y, int size, Color c);
    void draw() const;
    void setText(const char* t);
};