#include "CpuGame.h"
#include <iostream>

CpuGame::CpuGame() : BaseGame()
{
}


CpuGame::~CpuGame()
{
}

void CpuGame::Run()
{
	BaseGame::Run();
	//game logic
}

void CpuGame::Draw()
{
}

void CpuGame::EndGame()
{
	BaseGame::EndGame();

	std::cout << "CPU GAME TIME: " << this->secondsElapsed;
}
