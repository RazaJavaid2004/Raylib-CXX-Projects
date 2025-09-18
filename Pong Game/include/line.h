/*
int startX = screenWidth / 2;
    int startY = 0;
    int endX = startX;
    int endY = screenHeight;
*/

#pragma once
#include <raylib.h>

class Line {
    int startX;
    int startY;
    int endX;
    int endY;
    Color color;
    public:
    Line(int sX, int sY, int eX, int eY, Color c);
    void draw() const;
};