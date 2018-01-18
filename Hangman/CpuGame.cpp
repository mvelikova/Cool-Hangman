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
	this->mistakes = 0;
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
	if (this->game_level != GameLevel::Pro)
	{
		std::cout << "What's the first letter of your word" << std::endl;

		char a;
		a = Console::ReadKey();
		this->hidden_word[0] = a;
		this->used_letters.insert(a);
		SetCommonLetterInHiddenWord(a);

		if (this->game_level == GameLevel::Easy)
		{
			std::cout << "What's the last letter of your word" << std::endl;
			a = Console::ReadKey();
			this->hidden_word.back() = a;
			this->used_letters.insert(a);
			SetCommonLetterInHiddenWord(a);
		}
	}
	//computer starts guessing here
	WordsManager* wordsManager = new WordsManager();
	std::set<std::string> filtered = wordsManager->Filter(Helpers::all_words, this->hidden_word.size());

	if (this->hidden_word[0] != '_')
	{
		char letter = this->hidden_word[0];

		std::vector<int> indexes;

		for (int i = 0; i < this->hidden_word.size(); i++)
		{
			if (this->hidden_word[i] == letter)
				indexes.push_back(i);
		}
		wordsManager->Filter(filtered, letter, indexes); //update filtered by letter with indexes
	}

	if (this->hidden_word.back() != '_')
	{
		char letter = this->hidden_word.back();

		std::vector<int> indexes;

		for (int i = 0; i < this->hidden_word.size(); i++)
			if (this->hidden_word[i] == letter)
				indexes.push_back(i);

		wordsManager->Filter(filtered, letter, indexes); //update filtered by letter with indexes
	}
	bool guessWordThatIsNotInTheDictionary = false;

	while (mistakes <= 6 && filtered.size() != 1)
	{
		Console::Clear();

		int delimiters = 1;

		for (auto letter : this->hidden_word)
		{
			std::string spaces(delimiters, ' ');
			std::cout << letter << spaces;
		}

		std::cout << std::endl;
		std::vector<int> averageUsedLetters;
		if (guessWordThatIsNotInTheDictionary)
		{
			averageUsedLetters = wordsManager->GetOrderedLettersCloseTo50Percent(Helpers::all_words);
		}
		else
		{
			averageUsedLetters = wordsManager->GetOrderedLettersCloseTo50Percent(filtered);//not ordered
		}
		//	char mostUsedLetter = wordsManager->GetMostCommonLetter(filtered);
		char avarageUsedLetter;

		int minimalDiffIndex = 0;

		for (int i = 0; i < averageUsedLetters.size(); ++i)
		{
			if (this->used_letters.find(i+97) == this->used_letters.end())
			{
				minimalDiffIndex = i;
				break;
			}
		}
		for (int i = 1; i < averageUsedLetters.size(); ++i)
		{
			if (this->used_letters.find(i+97) == this->used_letters.end() && 50 - averageUsedLetters[i] <= 50 - averageUsedLetters[
				minimalDiffIndex])
			{
				minimalDiffIndex = i;
			}
		}

		avarageUsedLetter = minimalDiffIndex + 97;

		std::cout << "Is there a letter '" << avarageUsedLetter << "' ?" << std::endl;
		std::cout << "Press y/n" << std::endl;

		char ans;
		ans = Console::ReadKey();

		while (ans != 'y' && ans != 'n')
		{
			ans = Console::ReadKey();
		}

		if (ans == 'y')
		{
			this->SetCommonLetterInHiddenWord(avarageUsedLetter);
			std::vector<int> indexes;
			this->used_letters.insert(avarageUsedLetter);

			for (int i = 0; i < this->hidden_word.size(); i++)
			{
				if (this->hidden_word[i] == avarageUsedLetter)
					indexes.push_back(i);
			}
			wordsManager->Filter(filtered, avarageUsedLetter, indexes); //update filtered by letter with indexes
		}
		else
		{
			used_letters.insert(avarageUsedLetter);
			wordsManager->FilterByMissingChar(filtered,avarageUsedLetter);
			mistakes++;
		}

		this->DrawHangman(mistakes);
	}
	if (mistakes == 7)
	{
		this->DrawHangman(mistakes);
	}
	else if (filtered.size() == 1)
	{
		std::cout << "Is'" << *filtered.begin() << "' your word?" << std::endl;
		std::cout << "Press y/n" << std::endl;

		char ans;
		ans = Console::ReadKey();
		while (ans != 'y' && ans != 'n')
		{
			ans = Console::ReadKey();
		}

		if (ans == 'y')
		{
			Console::Clear();
			std::cout << "YOU WON!!!" << std::endl;
		}
		else
		{
			mistakes++;
			guessWordThatIsNotInTheDictionary = true;
		}
	}
	delete wordsManager;
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
			std::cout << "Press Esc to continue, Enter to change leter" << std::endl;
			break;
		case KEY_RIGHT:
		case KEY_DOWN:
			(idx == hidden_word_size - 1) ? idx = 0 : idx++;
			DrawWordGuesser(idx);
			std::cout << "Press Esc to continue, Enter to change leter" << std::endl;
			break;
		case ENTER:
			//set letter
			if (this->hidden_word[idx] == '_')
			{
				this->hidden_word[idx] = letter;
			}
			else if (this->hidden_word[idx] == letter)
			{
				this->hidden_word[idx] = '_';
			}

			DrawWordGuesser(idx);
			std::cout << "Press Esc to continue, Enter to change leter" << std::endl;
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
