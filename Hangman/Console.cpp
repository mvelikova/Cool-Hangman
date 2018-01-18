#include "Console.h"
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <iostream>

void Console::Clear()
{
#if defined(_WIN32) //if windows
	system("cls");

#else
	system("clear");    //if other
#endif  //finish
}

void Console::SetCursorPosition(int x, int y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(output, pos);
}

void Console::SetSize(int width, int height)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	_CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hConsole, &info);

	if (width > info.dwMaximumWindowSize.X - 1)
	{
		width = info.dwMaximumWindowSize.X - 1;
	}

	if (height > info.dwMaximumWindowSize.Y - 1)
	{
		height = info.dwMaximumWindowSize.Y - 1;
	}

	SMALL_RECT windowMaxSize = {0, 0, width, height};

	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowMaxSize))
	{
		std::cout << "SetConsoleWindowInfo failed with error " << GetLastError() << std::endl;
	}

	if (!SetConsoleTitle("TEST"))
	{
		std::cout << "SetConsoleTitle failed with error " << GetLastError() << std::endl;
	}
}

Console::Console()
{
}


Console::~Console()
{
}
