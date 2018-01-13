#include "GameStarter.h"
#include "Console.h"
#include <iostream>

GameStarter::GameStarter()
{
}


GameStarter::~GameStarter()
{
}

void GameStarter::Start(const GameType gameType)
{
	Console::Clear();

	switch (gameType)
	{
		case ComputerGuessing:
			std::cout << "Computer guessing chosen" << std::endl;
			break;
		case PlayerGuessing:
			std::cout << "Player guessing chosen" << std::endl;
			break;
	}
}
