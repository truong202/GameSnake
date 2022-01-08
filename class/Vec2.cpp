#pragma once
#include <iostream>

class Vec2
{
public:
    int x, y;
    Vec2();
    Vec2(int ox, int oy);
};
Vec2::Vec2() {}
Vec2::Vec2(int ox, int oy)
{
    x = ox;
    y = oy;
}