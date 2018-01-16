#include "CpuGame.h"
#include <iostream>

CpuGame::CpuGame(std::string word, GameLevel game_level) : BaseGame(word,game_level)
{
}


CpuGame::~CpuGame()
{
}

void CpuGame::Run()
{
	BaseGame::Run();
	this->Draw();
}

void CpuGame::Draw()
{
	std::cout << "CPU guessing (" << this->game_level << ")" << std::endl;
	std::cout << "Points: " << this->points << std::endl;
	std::cout << "Time elapsed: " << this->get_current_seconds_elapsed() << std::endl;
}

void CpuGame::EndGame()
{
	BaseGame::EndGame();
}

CpuGame::CpuGame()
{
}
