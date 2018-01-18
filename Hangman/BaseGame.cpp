#include "BaseGame.h"
#include <iostream>
#include <ctime>
#include "Console.h"
#include <conio.h>
#include "Constants.h"

BaseGame::BaseGame( GameLevel game_level)
{
	//Initialization
	this->points = 0;
	this->secondsElapsed = 0;
	this->game_level = game_level;
}

BaseGame::~BaseGame()
{
	
}

inline void BaseGame::Run()
{
	this->game_level = this->PickLevel();
	this->begin = clock();
}

void BaseGame::DrawHangman(int mistakes)
{
	if (mistakes==1)
	{
		Console::SetCursorPosition(30, 38);
		std::cout << Constants::Gibbet1[0];
	}
	if (mistakes == 2)
	{
		DrawHangman(mistakes - 1);

		int y = 37;
		for (auto element : Constants::Gibbet2)
		{
			Console::SetCursorPosition(30, y);
			std::cout << element;
			y--;
		}

	}
		if (mistakes == 3)
		{
			DrawHangman(mistakes - 1);

			int y = 2;
			for (auto element : Constants::Gibbet3)
			{
				Console::SetCursorPosition(38, y);
				std::cout << element;
				y--;
			}

		}
		if (mistakes == 4)
		{
			DrawHangman(mistakes - 1);

			int y = 3;
			for (auto element : Constants::Gibbet4)
			{
				Console::SetCursorPosition(39, y);
				std::cout << element;
				y++;
			}

		}
		if (mistakes == 5)
		{
			DrawHangman(mistakes - 1);

			int y = 5;
			for (auto element : Constants::HangmanHead)
			{
				Console::SetCursorPosition(41, y);
				std::cout << element;
				y++;
			}

		}
		if (mistakes == 6)
		{
			DrawHangman(mistakes - 1);

			int y = 12;
			for (auto element : Constants::HangmanHands)
			{
				Console::SetCursorPosition(40, y);
				std::cout << element;
				y++;
			}

		}
		if (mistakes == 7)
		{
			DrawHangman(mistakes - 1);

			int y = 25;
			for (auto element : Constants::HangmanLegs)
			{
				Console::SetCursorPosition(40, y);
				std::cout << element;
				y++;
			}
			Console::SetCursorPosition(56, 8);
			std::cout << "X";
			Console::SetCursorPosition(59, 8);
			std::cout << "X";
			Console::SetCursorPosition(70, 8);
			std::cout << "DEAD!";
		}
		
}

void BaseGame::EndGame()
{
	this->end = clock();
	this->secondsElapsed = double(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Points: " << this->points << std::endl;

}

double BaseGame::get_current_seconds_elapsed()
{
	clock_t now = clock();
	return double(now - begin) / CLOCKS_PER_SEC;
}

GameLevel BaseGame::PickLevel()
{
	Console::Clear();
	PrintLevels(GameLevel::Easy);

	int menuOption = 0;
	const int options_size = GameLevel::Pro + 1;
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

	for (int i = GameLevel::Easy; i != GameLevel::Pro + 1; i++)
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
