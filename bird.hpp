#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include "graphics.h"
#include "point.hpp"
const int screenWidth = getmaxwidth();
const int screenHeight = getmaxheight();

using namespace std;

class Bird
{
private:
    Point p;
    int score = 0;

public:
    Bird(int centerX, int centerY);
    void draw(int color) const;
    int getCenterX();
    int getCenterY();
    void undraw() const;
    void move(int dx);
    void earn();
    int getScore();
};

#endif