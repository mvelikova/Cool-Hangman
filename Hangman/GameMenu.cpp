#include "GameMenu.h"
#include "GameType.h"
#include "Console.h"
#include "Constants.h"
#include <conio.h>
#include <iostream>

GameMenu::GameMenu(GameStarter* game_starter): game_starter(game_starter)
{
	this->menu_options = {
		"Guess word", "Let computer guess your word"
	};
}


GameMenu::~GameMenu()
{
	delete this->game_starter;
}

void GameMenu::Run()
{
	//draw menu on screen
	Console::Clear();
	this->Draw();
}

void GameMenu::Draw()
{
	int menuOption = 0;
	int options_size = this->menu_options.size();

	this->DrawMenuOptions(menuOption);
	char c = 0;

	bool hasSelectedOption = false;

	do
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
			std::cout << "Up" << std::endl;//key up
			(menuOption == 0) ? (menuOption = options_size - 1) : menuOption--;
			this->DrawMenuOptions(menuOption);
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			std::cout << "Down" << std::endl; // key down
			menuOption = ++menuOption % options_size;
			this->DrawMenuOptions(menuOption);
			break;
		case ENTER:
			std::cout << "Enter" << std::endl; // key right
			hasSelectedOption = true;
			break;
		default:
			std::cout << std::endl << "null" << std::endl; // not arrow
			break;
		}
	}
	while (!hasSelectedOption);

	this->game_starter->Start(static_cast<GameType>(menuOption));

}

GameMenu::GameMenu()
{
}

void GameMenu::DrawMenuOptions(int selectedOption)
{
	Console::Clear();

	int num = 0;

	for (int i = 0; i < this->menu_options.size(); ++i)
	{
		(i == selectedOption) ? std::cout << "-->" : std::cout << "   ";
		std::cout << ++num << ". " << this->menu_options[i] << std::endl;
	}
}
