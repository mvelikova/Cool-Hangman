#include "Console.h"
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <string>

void Console::Clear()
{
#if defined(_WIN32) //if windows
	system("cls");

#else
	system("clear");    //if other
#endif  //finish
}

void Console::SetCursorPosition(int x,int y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(output, pos);
}
Console::Console()
{
}


Console::~Console()
{
}
