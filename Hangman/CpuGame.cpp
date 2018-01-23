#include "CpuGame.h"
#include <iostream>
#include "Constants.h"
#include "Console.h"
#include "Helpers.h"
#include "Messages.h"
#include "InputWriter.h"

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
	Console::Clear();
	int n;
	std::cout << Messages::GiveTheSizeOfTheWord << std::endl;
	std::cin >> n;
	std::string hidden(n, WORD_GUESSER_HIDDEN_CHAR);
	guesser->SetHiddenWord(hidden);

	this->Draw();
	this->GiveStartingLetters();

	WordsManager::current_game_words = guesser->FilterBySizeAndLetters();

	while (!GameShouldEnd())
	{
		this->Draw();
		Turn();
	}

	std::string path = "..\\" + Constants::DictionaryFilePath;
	std::ofstream ofs;
	InputWriter* ir = new InputWriter(ofs);

	Console::Clear();

	if (guesser->WordIsGuessed())
	{
		std::cout << Messages::CpuWon << std::endl;

		//cpu guessed word that is not in file
		if (WordsManager::current_game_words.size() == 0)
		{
			std::cout << Messages::CpuGuessedNonExistentWord << std::endl;
			std::string word = this->guesser->GetHiddenWord();
			ir->Write(word, path); //write word to file
			WordsManager::all_words[word.size()].insert(word); //write to in-memory dictionary
		}
	}
	else if (WordsManager::current_game_words.size() == 0) //cpu couldn't guess the word
	{
		std::cout << Messages::WhatWasTheWord << std::endl;
		this->DrawHangman(this->guesser->GetMistakes());

		std::string word;
		std::cin >> word;

		ir->Write(word, path); //write word to file
		WordsManager::all_words[word.size()].insert(word); //write to in-memory dictionary
	}
	else
	{
		std::cout << Messages::CpuLost << std::endl;
		this->DrawHangman(this->guesser->GetMistakes());
	}

	delete ir;
}

void CpuGame::Draw()
{
	Console::Clear();
	this->DrawHangman(guesser->GetMistakes());
}

void CpuGame::SuggestLetter()
{
	char letter = guesser->SuggestMostAverageLetter();
	//	char letter = guesser->SuggestMostCommonLetter();

	std::cout << "Is there a letter '" << letter << "' ?" << std::endl;
	std::cout << Messages::PressYorN << std::endl;

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

	//more than one words left
	if (WordsManager::current_game_words.size() > 1)
	{
		guesser->FillterByAnswerAndLetter(letter, ans);
	}
}

/**
 * \brief CPU suggests a whole word when the current_game_words is filtered down to a single word.
 * \return true - if the word is what the player thinks of, false - if not
 */
bool CpuGame::SuggestWord()
{
	std::string lastWord = *WordsManager::current_game_words.begin();
	std::cout << "Is '" << lastWord << "' your word?" << std::endl;
	std::cout << Messages::PressYorN << std::endl;

	char ans;
	ans = Console::ReadKey();

	while (ans != 'y' && ans != 'n')
	{
		ans = Console::ReadKey();
	}

	if (ans == 'y')
	{
		return true;
	}

	WordsManager::current_game_words.clear();
	return false;
}

void CpuGame::Turn()
{
	Console::SetCursorPosition(0, 0);

	//one word left
	if (WordsManager::current_game_words.size() == 1)
	{
		if (this->SuggestWord())
		{
			std::string lastWord = *WordsManager::current_game_words.begin();
			guesser->SetHiddenWord(lastWord);
			return;
		}
		else //the word suggested is not what the player thought of
		{
			this->guesser->addMistake();

			Console::Clear();

			this->DrawHangman(guesser->GetMistakes());

			Console::SetCursorPosition(0, 0);
		}
	}

	//more than one words left
	this->SuggestLetter();
	this->DrawHangman(guesser->GetMistakes());
}

void CpuGame::EndGame()
{
	BaseGame::EndGame();
}

CpuGame::CpuGame()
{
}

void CpuGame::GiveStartingLetters()
{
	if (this->game_level != GameLevel::Pro)
	{
		std::cout << Messages::WhatsTheFirstLetter << std::endl;

		char a;
		a = Console::ReadKey();
		guesser->SetLetterInHiddenWord(0, a);
		guesser->AddLetterToUsed(a);
		SetCommonLetterInHiddenWord(a);

		if (this->game_level == GameLevel::Easy)
		{
			std::cout << Messages::WhatsTheLastLetter << std::endl;
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
	std::cout << Messages::NavigationControls << std::endl;

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
			std::cout << Messages::NavigationControls << std::endl;
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			(idx == hidden_word_size - 1) ? idx = 0 : idx++;
			DrawPlayerWordGuesser(idx);
			std::cout << Messages::NavigationControls << std::endl;
			break;
		case SPACE:
			//set letter
			if (guesser->GetHiddenWord()[idx] == WORD_GUESSER_HIDDEN_CHAR)
			{
				guesser->SetLetterInHiddenWord(idx, letter);
			}
			else if (guesser->GetHiddenWord()[idx] == letter)
			{
				guesser->SetLetterInHiddenWord(idx, WORD_GUESSER_HIDDEN_CHAR);
			}

			DrawPlayerWordGuesser(idx);
			std::cout << Messages::NavigationControls << std::endl;
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
