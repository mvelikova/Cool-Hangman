#include "BaseGame.h"
#include <iostream>
#include <ctime>
#include "Console.h"
#include <conio.h>
#include "Constants.h"

inline void BaseGame::Run()
{
	this->points = 0;
	this->secondsElapsed = 0;
	this->level = this->PickLevel();

	this->begin = clock();
}

void BaseGame::EndGame()
{
	this->end = clock();
	this->secondsElapsed = double(end - begin) / CLOCKS_PER_SEC;
}

GameLevel BaseGame::PickLevel()
{
	Console::Clear();
	PrintLevels(GameLevel::Easy);

	int menuOption = 0;
	const int options_size = GameLevel::Pro;
	char c;

	while (true)
	{
		c = _getch();

		//catch if an arrow is passed
		if (c == -32)
		{
			//determine which arrow
			c = _getch();
		}

		switch (c)
		{
		case KEY_LEFT:
		case KEY_UP:
			(menuOption == 0) ? (menuOption = options_size - 1) : menuOption--;
			this->PrintLevels(menuOption);
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			menuOption = ++menuOption % options_size;
			this->PrintLevels(menuOption);
			break;
		case ENTER:
			return static_cast<GameLevel>(menuOption);
		default:
			break;
		}
	}
}

void BaseGame::PrintLevels(const int current_selection = 0)
{
	Console::Clear();

	for (int i = GameLevel::Easy; i != GameLevel::Pro; i++)
	{
		GameLevel foo = static_cast<GameLevel>(i);

		if (i == current_selection)
		{
			std::cout << "-->" << foo << std::endl;
		}
		else
		{
			std::cout << "   " << foo << std::endl;
		}
	}
}

BaseGame::~BaseGame()
{
	this->BaseGame::EndGame();
	std::cout << "WHOLE GAME OBJECT TIME: " << this->secondsElapsed;
}

BaseGame::BaseGame()
{
	this->BaseGame::Run();
}
