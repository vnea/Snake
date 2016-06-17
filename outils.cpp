#include "outils.h"
#include <windows.h>

void gotoxy(int posX, int posY)
{
    static HANDLE h = NULL;

    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD c = {posX, posY};
    SetConsoleCursorPosition(h,c);
}

void ShowCursor(bool show)
{
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE );
    GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
    structCursorInfo.bVisible = show;
    SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}

void textcolor(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO Info ;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info) ;
    textattr((Info.wAttributes & 0xF0) | color);
}

void textattr(int attr)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), attr);
}
