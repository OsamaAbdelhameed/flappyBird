#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <string>
#include "graphics.h"
#include "bird.hpp"
#include "room.hpp"

class Obstacle
{
protected:
    int centerX;
    Bird *bird;
public:
    Obstacle(int centerX =0, Bird *bird =NULL);
    void setCenterX(int centerX =0);
    int getCenterX();
    void setBird(Bird *bird = NULL);
    Bird *getBird();
    void undraw();
    void move(int dx, int color);

    virtual void draw(int color) =0;
    virtual void isHit() =0;
    virtual void onHit() =0;
};

#endif