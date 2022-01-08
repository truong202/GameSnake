#pragma once

#include "Vec2.cpp"
#include "Console.cpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Food
{
private:
    // Vec2 body[10];
    int count;

public:
    Vec2 body[10];
    Food();
    // Food(int count);
    void display();
    void remove();
};

Food::Food()
{
    srand(time(NULL));
    count = 1;
    body[0].x = 1 + rand() % 99;
    body[0].y = 1 + rand() % 35;
}
// Food::Food(int count)
// {
//     this->count = count;
//     body[0].x = rand() % 99;
//     body[0].y = rand() % 34;

//     body[1].x = body[0].x + 1;
//     body[1].y = body[0].y;

//     body[2].x = body[0].x;
//     body[2].y = body[0].y + 1;

//     body[3].x = body[0].x + 1;
//     body[3].y = body[0].y + 1;
// }

void Food::display()
{

    for (int i = 0; i < count; i++)
    {
        gotoxy(body[i].x, body[i].y);
        textColor("♦", LIGHT_YELLOW);
    }
}

void Food::remove()
{
    for (int i = 0; i < count; i++)
    {
        gotoxy(body[i].x, body[i].y);
        cout << " ";
    }
}