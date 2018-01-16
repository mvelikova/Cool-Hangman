#include "PlayerGame.h"
#include <iostream>


PlayerGame::PlayerGame() : BaseGame()
{
}


PlayerGame::~PlayerGame()
{
}

void PlayerGame::Run()
{
	BaseGame::Run();
	//game logic
}

void PlayerGame::Draw()
{
}

void PlayerGame::EndGame()
{
	BaseGame::EndGame();

	std::cout << "PLAYER GAME TIME: " << this->secondsElapsed;
}
