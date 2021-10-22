#include "obstacle.hpp"

Obstacle::Obstacle(int centerX, Bird *bird) { 
    this->centerX = centerX; 
    this->bird = bird;    
}
void Obstacle::setCenterX(int centerX) { this->centerX = centerX; }
int Obstacle::getCenterX() { return centerX; }
void Obstacle::setBird(Bird *bird){
    this->bird = bird;
}
Bird *Obstacle::getBird(){ return bird;}
void Obstacle::undraw() { draw(BLACK); }
void Obstacle::move(int dx, int color)
{
    undraw();
    centerX -= dx;
    draw(color);
}