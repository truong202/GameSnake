#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "./class/Snake.cpp"
#include "./class/Console.cpp"
#include "./class/Food.cpp"

Snake *snake = new Snake();
Food *food = new Food();
int score = 0;
int timeSleep = 150;

void runGame();
int control(int key);

int main(int argc, char const *argv[])
{
    clrscr();
    setWindowSize(138, 38);
    setting();
    displayUI("./data/map1.txt");
    runGame();
    return 0;
}

void runGame()
{
    snake->display();
    food->display();
    gotoxy(108, 2);
    cout << "Diem: " << score;
    while (true)
    {
        if (snake->isDie())
        {
            gotoxy(137 / 2 - 15, 37 / 2);
            cout << "Toang Toang Toang!";
            gotoxy(137 / 2 - 15, 37 / 2 + 2);
            cout << "Bam enter de thoat";
            getchar();
            break;
        }
        if (snake->body[0].x == food->body[0].x && snake->body[0].y == food->body[0].y)
        {
            food->remove();
            food = new Food();
            food->display();
            snake->add();
            score += 1000;
            if (timeSleep > 70)
            {
                timeSleep -= 5;
            }
            else
            {
                timeSleep -= 3;
            }
            if (timeSleep < 10)
            {
                timeSleep = 10;
            }
            gotoxy(108, 2);
            cout << "Diem: " << score;
        }
        snake->move();
        if (kbhit())
        {
            int key = _getch();
            if (key == 27)
                break;
            control(key);
        }

        Sleep(timeSleep);
    }
}

int control(int key)
{
    switch (key)
    {
    case 'w':
    case 'W':
    case 72:
        if (snake->getStatus() != DOW)
            snake->setStatus(UP);
        break;
    case 's':
    case 'S':
    case 80:
        if (snake->getStatus() != UP)
            snake->setStatus(DOW);
        break;
    case 'a':
    case 'A':
    case 75:
        if (snake->getStatus() != RIGHT)
            snake->setStatus(LEFT);
        break;
    case 'd':
    case 'D':
    case 77:
        if (snake->getStatus() != LEFT)
            snake->setStatus(RIGHT);
        break;
    case 13:
        if (snake->getStatus() != STOP)
            snake->setStatus(STOP);
    }
    //     }
}
