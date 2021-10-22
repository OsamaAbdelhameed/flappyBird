#include "room.hpp"
#include "obstacle.hpp"


Room::Room()
{
        xTitle = screenWidth / 4;
        yTitle = screenHeight / 4;
        setfillstyle(SOLID_FILL, BLACK);
        bar(0, 0, screenWidth, screenHeight);
        settextstyle(6, 0, 10);
        setcolor(YELLOW);
}


void Room::home()
{
    char title[15] = "Flappy Bird";
    char play[15] = "Play";
    char quit[15] = "Quit";
    outtextxy(xTitle, yTitle, title);
    settextstyle(6, 0, 8);
    int btnStartX = screenWidth / 2 - screenWidth / 10;
    int btnEndX = screenWidth / 2 + screenWidth / 10;

    int pbtnStartY = screenHeight / 2 - screenHeight / 15;
    int pbtnEndY = screenHeight / 2 + screenHeight / 15;

    int qbtnStartY = pbtnEndY + screenHeight / 15;
    int qbtnEndY = pbtnEndY + screenHeight / 5;

    rectangle(btnStartX, pbtnStartY, btnEndX, pbtnEndY);
    rectangle(btnStartX, qbtnStartY, btnEndX, qbtnEndY);
    setcolor(WHITE);
    outtextxy(btnStartX + 100, pbtnStartY + 30, play);
    outtextxy(btnStartX + 100, qbtnStartY + 30, quit);
    
    int xClick, yClick;
    while (!kbhit())
    {
        getmouseclick(WM_LBUTTONDOWN, xClick, yClick);
        if ((xClick > btnStartX) &&
            (xClick < btnEndX) &&
            (yClick > pbtnStartY) &&
            (yClick < pbtnEndY))
        {
            setfillstyle(SOLID_FILL, BLACK);
            bar(0, 0, screenWidth, screenHeight);
            delay(20);
            break;
        }
        else if((xClick > btnStartX) &&
            (xClick < btnEndX) &&
            (yClick > qbtnStartY) &&
            (yClick < qbtnEndY))
        {
            delay(20);
            exit(1);
        }
    }

}

void Room::gameOver(int _score)
{
    char title[15] = "Game Over";
    outtextxy(xTitle, yTitle, title);
    settextstyle(6, 0, 5);
    setcolor(GREEN);
    char result[20] = "Your score is : ";
    char score[2];
    itoa (_score,score,10);
    outtextxy(xTitle * 1.5, yTitle * 2, result);
    outtextxy(xTitle * 2.3, yTitle * 2, score);
    delay(10000);
    exit(1);
}