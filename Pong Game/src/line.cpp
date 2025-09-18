#include "line.h"

Line::Line(int sX, int sY, int eX, int eY, Color c) : startX(sX), startY(sY), endX(eX), endY(eY), color(c) {}

void Line::draw() const {
        DrawLine(startX, startY, endX, endY, color);
}