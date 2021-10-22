#include "coin.hpp"

Coin::Coin(int centerX, Bird *bird, int centerY) : Obstacle(centerX,  bird)
{
    this->centerY = centerY;
    draw(YELLOW);
}
void Coin::draw(int color)
{
    if (!isEarned)
    {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(centerX, centerY, 50, 50);
        setcolor(BLACK);
        circle(centerX, centerY, 40);
        circle(centerX, centerY, 41);
        circle(centerX, centerY, 42);
    }
}
void Coin::setCenterY(int cy) { centerY = cy; }
int Coin::getCenterY() const { return centerY; }
void Coin::isHit()
{
    if (!isEarned)
    {
        int dx = abs(bird->getCenterX() - getCenterX());
        int dy = abs(bird->getCenterY() - getCenterY());
        int sum_rx = 50 + 40;
        int sum_ry = 50 + 40;
        if ((dx <= sum_rx) && (dy <= sum_ry))
            onHit();
    }
}
void Coin::onHit()
{
    bird->earn();
    string pasSound = "sounds/BirdScoringSound.wav";
    PlaySound(TEXT(pasSound.c_str()), NULL, SND_ASYNC);
    undraw();
    isEarned = true;
}