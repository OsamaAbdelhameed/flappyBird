#include "bird.hpp"
#include "coin.hpp"
#include "pipe.hpp"
#include "room.hpp"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    initwindow(screenWidth, screenHeight, "Flappy Bird Game");
    Bird player(screenWidth / 6, screenHeight / 2);
    setcolor(BLACK);
    Room game;
    game.home();
    player.draw(RED);

    int totalObstacles = 20;
    Obstacle *obstacles[totalObstacles];
    int order[totalObstacles];
    srand (time(NULL));
    int position = 0;
    for (int i = 0; i < totalObstacles; i++)
    {
        if (rand() % 2 == 1)
        {
            obstacles[i] = new Pipe(screenWidth + position, &player, (rand() % 3) + 1);
            order[i] = GREEN;
        } 
        else
        {
            obstacles[i] = new Coin(screenWidth + position, &player, (rand() % (screenHeight / 2)) + screenHeight / 4);
            order[i] = YELLOW;
        }
        position += 400;
    }
    char score[2];
    while(true)
    {
        for(int i = 0; i < totalObstacles; i++)
        {
            obstacles[i]->move(25, order[i]);
            delay(10);
        }
        player.move(25);
        if(kbhit() && getch() == ' ')
            player.move(-50);
        for(int i = 0; i < totalObstacles; i++)
           obstacles[i]->isHit();

        settextstyle(8,0,7);
        setcolor(WHITE);
        itoa (player.getScore(),score,10);
        outtextxy(100, 100, score);
    }
    system("pause");
    return 0;
}
