#include "score.h"

Score::Score(const char* t, int x, int y, int size, Color c) : text(t), posX(x), posY(y), fontSize(size), color(c) {}

void Score::draw() const {
        DrawText(text, posX, posY, fontSize, color);
}

void Score::setText(const char* t) {
        text = t;
}