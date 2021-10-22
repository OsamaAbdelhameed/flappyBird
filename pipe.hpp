#ifndef PIPE_H
#define PIPE_H

#include "obstacle.hpp"

using namespace std;

class Pipe : public Obstacle
{
private:
    int topCenterY, bottomCenterY, pattern; // 1 to 3

public:
    Pipe(int centerX =0, Bird *bird =NULL, int pattern =0);
    void draw(int color);
    void setTopCenterY(int tcy);
    void setBottomCenterY(int bcy);
    int getTopCenterY() const;
    int getBottomCenterY() const;
    void isHit();
    void onHit();
};

#endif