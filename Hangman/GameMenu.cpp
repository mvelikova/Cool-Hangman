#include "GameMenu.h"
#include "GameType.h"
#include "Console.h"
#include "Constants.h"
#include <iostream>
#include "Messages.h"

GameMenu::GameMenu()
{
}

GameMenu::GameMenu(GameStarter* game_starter): game_starter(game_starter)
{
	this->menu_options = {
		Messages::GameMenuOption1, Messages::GameMenuOption2
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
		c = Console::ReadKey();

		//catch if an arrow is passed
		if (c == -32)
		{
			//determine which arrow
			c = Console::ReadKey();
		}

		switch (c)
		{
		case KEY_LEFT:
		case KEY_UP:
			(menuOption == 0) ? (menuOption = options_size - 1) : menuOption--;
			this->DrawMenuOptions(menuOption);
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			menuOption = ++menuOption % options_size;
			this->DrawMenuOptions(menuOption);
			break;
		case ENTER:
			hasSelectedOption = true;
			break;
		default:
			break;
		}
	}
	while (!hasSelectedOption);

	this->game_starter->Start(static_cast<GameType>(menuOption));
}

void GameMenu::DrawMenuOptions(int selectedOption)
{
	Console::Clear();
	for (int i = 0; i < Constants::HangmanTitleDrawing.size(); i++)
	{
		std::cout << Constants::HangmanTitleDrawing[i] << std::endl;
	}
	int num = 0;

	for (int i = 0; i < this->menu_options.size(); ++i)
	{
		Console::SetCursorPosition(40, 15 + i);
		(i == selectedOption) ? std::cout << "-->" : std::cout << "   ";
		std::cout << ++num << ". " << this->menu_options[i] << std::endl;
	}
}
