#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "graphics.h"
#include "bird.hpp"

using namespace std;

class Room{
    private:
        int xTitle, yTitle;
    public:
        Room();
        void home();
        void gameOver(int _score);
};

#endif