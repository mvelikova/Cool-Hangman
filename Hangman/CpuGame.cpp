#include "CpuGame.h"
#include <iostream>
#include "Constants.h"
#include "Console.h"
#include "Helpers.h"
#include "WordsManager.h"
#include <windows.h>

CpuGame::CpuGame(GameLevel game_level)
{
	this->game_level = game_level;
	this->guesser = new CpuWordGuesser;
}

CpuGame::~CpuGame()
{
	delete this->guesser;
}

void CpuGame::Run()
{
	BaseGame::Run();

	int n;
	std::cout << "Give the size of the word you're thinking of" << std::endl;
	std::cin >> n;
	std::string hidden(n, WORD_GUESSER_HIDDEN_CHAR);
	guesser->SetHiddenWord(hidden);

	this->Draw();
	this->RunLevelLogic();

	Helpers::current_game_words = guesser->FilterBySizeAndLetters();

	while (!GameShouldEnd())
	{
		this->Draw();
		Turn();
	}

	if (guesser->WordIsGuessed())
	{
		Console::Clear();

		std::cout << "I WON!!!   YOU LOST !!!" << std::endl;
	}

}

void CpuGame::Draw()
{
	Console::Clear();
	this->DrawHangman(guesser->GetMistakes());
}

void CpuGame::Turn()
{
	Console::SetCursorPosition(0, 0);
	if (Helpers::current_game_words.size() == 1)
	{
		std::string lastWord = *Helpers::current_game_words.begin();
		std::cout << "Is '" << lastWord << "' your word?" << std::endl;
		std::cout << "Press y/n" << std::endl;
		char ans;
		ans = Console::ReadKey();

		while (ans != 'y' && ans != 'n')
		{
			ans = Console::ReadKey();
		}

		if (ans == 'y')
		{
			guesser->SetHiddenWord(lastWord);
			return;
		}

		Helpers::current_game_words.clear();
		return;
	}
	//Suggest a letter 

	char letter = guesser->SuggestLetter1();
	//char letter = guesser->SuggestLetter2();

	std::cout << "Is there a letter '" << letter << "' ?" << std::endl;
	std::cout << "Press y/n" << std::endl;

	char ans;
	ans = Console::ReadKey();

	while (ans != 'y' && ans != 'n')
	{
		ans = Console::ReadKey();
	}

	if (ans == 'y')
	{
		this->SetCommonLetterInHiddenWord(letter);
	}
	else { guesser->addMistake(); }
	guesser->AddLetterToUsed(letter);

	if (Helpers::current_game_words.size() > 1)
	{
		guesser->FillterByAnswerAndLetter(letter, ans);
	}

	this->DrawHangman(guesser->GetMistakes());
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
	if (this->game_level != GameLevel::Pro)
	{
		std::cout << "What's the first letter of your word" << std::endl;

		char a;
		a = Console::ReadKey();
		guesser->SetLetterInHiddenWord(0, a);
		guesser->AddLetterToUsed(a);
		SetCommonLetterInHiddenWord(a);

		if (this->game_level == GameLevel::Easy)
		{
			std::cout << "What's the last letter of your word" << std::endl;
			a = Console::ReadKey();
			guesser->SetLetterInHiddenWord(guesser->GetHiddenWord().size() - 1, a);
			guesser->AddLetterToUsed(a);
			SetCommonLetterInHiddenWord(a);
		}
	}
}

void CpuGame::SetCommonLetterInHiddenWord(char letter)
{
	int idx = 0;
	int hidden_word_size = guesser->GetHiddenWord().size();

	bool settingLetters = true;
	DrawPlayerWordGuesser(idx);
	std::cout <<"Press Enter to continue, Space to change leter" << std::endl;

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
			DrawPlayerWordGuesser(idx);
			std::cout << "Press Enter to continue, Space to change leter" << std::endl;
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			(idx == hidden_word_size - 1) ? idx = 0 : idx++;
			DrawPlayerWordGuesser(idx);
			std::cout << "Press Enter to continue, Space to change leter" << std::endl;
			break;
		case SPACE:
			//set letter
			if (guesser->GetHiddenWord()[idx] == '_')
			{
				guesser->SetLetterInHiddenWord(idx, letter);
			}
			else if (guesser->GetHiddenWord()[idx] == letter)
			{
				guesser->SetLetterInHiddenWord(idx, '_');
			}

			DrawPlayerWordGuesser(idx);
			std::cout << "Press Enter to continue, Space to change leter" << std::endl;
			break;
		case ENTER:
			settingLetters = false;
			break;
		default:
			break;
		}
	}
	while (settingLetters);
}

void CpuGame::DrawPlayerWordGuesser(int index) const
{
	Console::Clear();

	int delimiters = 1;

	for (auto letter : guesser->GetHiddenWord())
	{
		std::string spaces(delimiters, ' ');
		std::cout << letter << spaces;
	}

	std::cout << std::endl;

	Helpers::DrawCursor(index, guesser->GetHiddenWord().size(), delimiters);
}

bool CpuGame::GameShouldEnd()
{
	return guesser->AllMistakesAreMade() || guesser->WordIsGuessed();
}
