#include "PlayerGame.h"
#include <iostream>


PlayerGame::PlayerGame(std::string word, GameLevel game_level) : BaseGame(word, game_level)
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
	std::cout << "Player guessing (" << this->game_level << ")" << std::endl;
	std::cout << "Points: " << this->points << std::endl;
	std::cout << "Time elapsed: " << this->get_current_seconds_elapsed() << std::endl;
}

void PlayerGame::EndGame()
{
	BaseGame::EndGame();
}

PlayerGame::PlayerGame()
{
}
