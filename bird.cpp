#include "bird.hpp"
#include <stdlib.h>
#include <time.h>


Bird::Bird(int centerX, int centerY) : p(centerX, centerY)
{
    score = 0;
}
void Bird::draw(int color) const
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse(p.getCenterX(), p.getCenterY(), 40, 40);
}
void Bird::undraw() const { draw(BLACK); }
int Bird::getCenterX(){return p.getCenterX();}
int Bird::getCenterY(){return p.getCenterY();}
void Bird::move(int dx)
{
    undraw();
    p.setCenterY(p.getCenterY() + dx);
    draw(RED);
}

void Bird::earn() { score++; }
int Bird::getScore() { return score; }
