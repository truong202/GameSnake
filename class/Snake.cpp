#pragma once

#include <iostream>
#include "Vec2.cpp"
#include "Console.cpp"
#include "textColor.cpp"

enum Status
{
    UP,
    DOW,
    LEFT,
    RIGHT,
    STOP
};

class Snake
{
private:
    // Vec2 body[100];
    int count;
    Status status;
    void remove()
    {
        // gotoxy(body[count - 1].x, body[count - 1].y);
        // cout << " ";
        for (int i = 0; i < count; i++)
        {
            gotoxy(body[i].x, body[i].y);
            cout << " ";
        }
    }
    void displayHead()
    {
        // gotoxy(body[0].x, body[0].y);
        // cout << "▓";
        // for (int i = 0; i < count; i++)
        // {
        //     gotoxy(body[i].x, body[i].y);
        //     cout << "▓";
        // }
    }

public:
    Vec2 body[100];
    Snake();
    void display();
    void add();
    void move();
    void setStatus(Status status);
    bool isDie();
    Status getStatus();
};

Snake::Snake()
{
    count = 1;
    body[0].x = 50;
    body[0].y = 15;
    status = RIGHT;
}

void Snake::display()
{
    gotoxy(body[0].x, body[0].y);
    textColor("☻", AQUA);
    for (int i = 1; i < count; i++)
    {
        gotoxy(body[i].x, body[i].y);
        textColor("O", LIGHT_AQUA);
    }
}

void Snake::add()
{
    for (int i = count; i > 0; i--)
    {
        body[i] = body[i - 1];
    }
    if (status == UP)
    {
        body[0].y--;
    }
    else if (status == DOW)
    {
        body[0].y++;
    }
    else if (status == LEFT)
    {
        body[0].x--;
    }
    else
    {
        body[0].x++;
    }
    count++;
}

void Snake::move()
{
    if (this->status != STOP)
    {
        remove();
        for (int i = count - 1; i > 0; i--)
        {
            body[i] = body[i - 1];
        }
        if (status == UP)
        {
            body[0].y--;
            if (body[0].y < 1)
            {
                body[0].y = 35;
            }
        }
        else if (status == DOW)
        {
            body[0].y++;
            if (body[0].y > 35)
            {
                body[0].y = 1;
            }
        }
        else if (status == LEFT)
        {
            body[0].x--;
            if (body[0].x < 1)
            {
                body[0].x = 99;
            }
        }
        else
        {
            body[0].x++;
            if (body[0].x > 99)
            {
                body[0].x = 1;
            }
        }
        display();
    }
}

void Snake::setStatus(Status status)
{
    this->status = status;
}

Status Snake::getStatus()
{
    return this->status;
}
bool Snake::isDie()
{
    for (int i = 1; i < count; i++)
    {
        if (body[i].x == body[0].x && body[i].y == body[0].y)
        {
            return true;
        }
    }
    return false;
}