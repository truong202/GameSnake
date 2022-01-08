// #include "console.h"

#pragma once

#include <conio.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include "textColor.cpp"
#include <string>
#include <string.h>

using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void setting();
void setWindowSize(int width, int height);
char getCursorChar();
void showScrollBar(bool show);
void disableResizeWindow();
void disableCtrButton(bool close, bool min, bool max);
void showCursor(bool CursorVisibility);
void disableSelection();
void gotoxy(int x, int y);
void setColor(int color);
void textColor(string text, int color);
void backgroundColor(string text, int textColor, int backgroundColor);
void resetColor();
void clrscr();

void setting()
{
    SetConsoleOutputCP(65001);
    disableCtrButton(0, 0, 1);
    disableResizeWindow();
    showScrollBar(false);
    showCursor(false);
    disableSelection();
}

void setWindowSize(int width, int height)
{
    string widthString = to_string(width);
    string heightString = to_string(height);
    string a = "MODE CON COLS=" + widthString + " LINES=" + heightString;
    system(a.c_str());
}

char getCursorChar()
{
    char c = '\0';
    CONSOLE_SCREEN_BUFFER_INFO con;
    // HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (handle != INVALID_HANDLE_VALUE &&
        GetConsoleScreenBufferInfo(handle, &con))
    {
        DWORD read = 0;
        if (!ReadConsoleOutputCharacterA(handle, &c, 1,
                                         con.dwCursorPosition, &read) ||
            read != 1)
            c = '\0';
    }
    return c;
}

void showScrollBar(bool show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, show);
}

void disableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void disableCtrButton(bool close, bool min, bool max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void disableSelection()
{
    SetConsoleMode(handle, ~ENABLE_QUICK_EDIT_MODE);
}

void showCursor(bool CursorVisibility)
{
    CONSOLE_CURSOR_INFO ConCurInf;
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = CursorVisibility;
    SetConsoleCursorInfo(handle, &ConCurInf);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle, coord);
}

void resetColor()
{

    SetConsoleTextAttribute(handle, 15);
}

void setColor(int color)
{
    SetConsoleTextAttribute(handle, color);
}

void backgroundColor(string text, int textColor, int backgroundColor)
{
    int color = backgroundColor * 16 + textColor;
    setColor(color);
    cout << text;
    resetColor();
}

void textColor(string text, int color)
{
    setColor(color);
    cout << text;
    resetColor();
}

void clrscr()
{
    system("cls");
}
void displayUI(string fileName)
{
    string getcontent;
    ifstream openfile(fileName.c_str());
    setColor(LIGHT_GREEN);
    if (openfile.is_open())
    {
        while (!openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
    }
    resetColor();
}
