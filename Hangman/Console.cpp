#include "Console.h"
#include <cstdlib>


void Console::Clear()
{
#if defined(_WIN32) //if windows
	system("cls");

#else
	system("clear");    //if other
#endif  //finish
}

Console::Console()
{
}


Console::~Console()
{
}
