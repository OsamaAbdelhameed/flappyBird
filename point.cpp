#include "point.hpp"

Point::Point(int centerX, int centerY){
    this->centerX = centerX;
    this->centerY = centerY;
}
void Point::setCenterX(int cx){
    this->centerX = cx;
}
void Point::setCenterY(int cy){
    this->centerY = cy;
}
int Point::getCenterX() const { return centerX; }
int Point::getCenterY() const { return centerY; }