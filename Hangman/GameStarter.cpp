#include "GameStarter.h"
#include "Console.h"
#include <iostream>
#include "BaseGame.h"
#include "CpuGame.h"
#include "PlayerGame.h"

GameStarter::GameStarter()
{
}


GameStarter::~GameStarter()
{
}

void GameStarter::Start(const GameType gameType)
{
	Console::Clear();

	BaseGame* game;

	switch (gameType)
	{
		case ComputerGuessing:
			game = new CpuGame();
			std::cout << "Computer guessing chosen" << std::endl;
			break;
		case PlayerGuessing:
		default:
			game = new PlayerGame();
			std::cout << "Player guessing chosen" << std::endl;
			break;
	}

	delete game;
}
