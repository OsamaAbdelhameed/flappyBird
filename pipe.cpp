#include "pipe.hpp"

Pipe::Pipe(int centerX, Bird *bird, int pattern) : Obstacle(centerX, bird)
{
    this->pattern = pattern;
    topCenterY = screenHeight * pattern * 0.1;
    bottomCenterY = (screenHeight - 2 * topCenterY - screenHeight * 0.2) / 2;
    draw(GREEN);
}
void Pipe::draw(int color)
{
    setfillstyle(XHATCH_FILL, color);
    bar(centerX - 50, 0, centerX + 50, topCenterY * 2);
    bar(centerX - 50, 2 * topCenterY + 0.2 * screenHeight, centerX + 50, screenHeight);
}
void Pipe::setTopCenterY(int tcy) { topCenterY = tcy; }
void Pipe::setBottomCenterY(int bcy) { bottomCenterY = bcy; }
int Pipe::getTopCenterY() const { return topCenterY; }
int Pipe::getBottomCenterY() const { return bottomCenterY; }
void Pipe::isHit()
{
    bool inXRange = bird->getCenterX() + 40 > getCenterX() - 50 && bird->getCenterX() - 40 < getCenterX() + 50;
    bool inYRange = bird->getCenterY() - 40 < 2 * getTopCenterY() || bird->getCenterY() + 40 > screenHeight - getBottomCenterY() * 2;
    if (inXRange && inYRange)
        onHit();
}
void Pipe::onHit() {
    Room endGame;
    endGame.gameOver(bird->getScore()); 
}