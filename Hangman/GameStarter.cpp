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
			game = new CpuGame(GameLevel::Easy);
			break;
		case PlayerGuessing:
		default:
			std::string word = "pishka";
			game = new PlayerGame(word, GameLevel::Easy);
			break;
	}
	game->Run();

	delete game;
}
