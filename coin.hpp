#ifndef COIN_H
#define COIN_H

#include "obstacle.hpp"

using namespace std;

class Coin : public Obstacle
{
private:
    int centerY;
    bool isEarned;

public:
    Coin(int centerX, Bird *bird, int centerY);
    void draw(int color);
    void setCenterY(int cy);
    int getCenterY() const;
    void isHit();
    void onHit();
};

#endif