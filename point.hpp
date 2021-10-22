#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "graphics.h"

using namespace std;

class Point{
    private:
        int centerX, centerY;
    public:
        Point(int centerX =0, int centerY =0);
        void setCenterX(int cx =0);
        void setCenterY(int cy =0);
        int getCenterX() const;
        int getCenterY() const;
};

#endif