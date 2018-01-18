#include "CpuGame.h"
#include <iostream>
#include "Constants.h"
#include "Console.h"
#include "Helpers.h"

CpuGame::CpuGame(GameLevel game_level)
{
	this->game_level = game_level;
}

CpuGame::~CpuGame()
{
}

void CpuGame::Run()
{
	BaseGame::Run();

	int n;
	std::cout << "Give the size of the word you're thinking of" << std::endl;
	std::cin >> n;

	std::string hidden(n, WORD_GUESSER_HIDDEN_CHAR);
	this->hidden_word = hidden;

	this->Draw();
	this->RunLevelLogic();
}

void CpuGame::Draw()
{
	Console::Clear();
	std::cout << "CPU guessing (" << this->game_level << ")" << std::endl;
}

void CpuGame::EndGame()
{
	BaseGame::EndGame();
}

CpuGame::CpuGame()
{
}

void CpuGame::RunLevelLogic()
{
	this->GiveStartingLetters();
}

void CpuGame::GiveStartingLetters()
{
	if (this->game_level == GameLevel::Pro) return;

	std::cout << "What's the first letter of your word" << std::endl;

	char a;
	a = Console::ReadKey();
	this->hidden_word[0] = a;

	SetCommonLetterInHiddenWord(a);

	if (this->game_level == GameLevel::Easy)
	{
		std::cout << "What's the last letter of your word" << std::endl;
		a = Console::ReadKey();
		this->hidden_word.back() = a;

		SetCommonLetterInHiddenWord(a);
	}

	//computer starts guessing here
}

void CpuGame::SetCommonLetterInHiddenWord(char letter)
{
	int idx = 0;
	int hidden_word_size = this->hidden_word.size();

	bool settingLetters = true;
	DrawWordGuesser(idx);
	std::cout << "Press Esc to continue..." << std::endl;

	do
	{
		char c;
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
			(idx == 0) ? idx = hidden_word_size - 1 : idx--;
			DrawWordGuesser(idx);
			std::cout << "Press Esc to continue..." << std::endl;
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			(idx == hidden_word_size - 1) ? idx = 0 : idx++;
			DrawWordGuesser(idx);
			std::cout << "Press Esc to continue..." << std::endl;
			break;
		case ENTER:
			//set letter
			this->hidden_word[idx] = letter;
			DrawWordGuesser(idx);
			std::cout << "Press Esc to continue..." << std::endl;

			break;
		case ESCAPE:
			settingLetters = false;
			break;
		default:
			break;
		}
	}
	while (settingLetters);
}

void CpuGame::DrawWordGuesser(int index) const
{
	Console::Clear();

	int delimiters = 1;

	for (auto letter : this->hidden_word)
	{
		std::string spaces(delimiters, ' ');
		std::cout << letter << spaces;
	}

	std::cout << std::endl;

	Helpers::DrawCursor(index, this->hidden_word.size(), delimiters);
}
