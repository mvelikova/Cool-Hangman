#include "CpuWordGuesser.h"
#include "Constants.h"
#include <iostream>
#include "Helpers.h"


CpuWordGuesser::CpuWordGuesser()
{
	this->wordsManager = new WordsManager();
	hidden_word = "";
}


CpuWordGuesser::~CpuWordGuesser()
{
	delete wordsManager;
}

void CpuWordGuesser::SetLetterInHiddenWord(int pos, char letter)
{
	this->hidden_word[pos] = letter;
}

void CpuWordGuesser::AddLetterToUsed(char letter)
{
	this->used_letters.insert(letter);
}

void CpuWordGuesser::SetHiddenWord(std::string word)
{
	this->hidden_word = word;
}

std::set<std::string> CpuWordGuesser::FilterBySizeAndLetters()
{
	//filter by size
	std::set<std::string> filtered = wordsManager->Filter(Helpers::all_words, this->hidden_word.size());

	//filter by  first and last letter if present
	char letter = this->hidden_word[0];
	std::vector<int> indexes;
	if (letter != '_')
	{
		indexes = IndexesOf(hidden_word, letter);
		wordsManager->Filter(filtered, letter, indexes); //update filtered by letter with indexes
	}
	letter = this->hidden_word.back();
	if (letter != '_' && letter != this->hidden_word[0])
	{
		indexes = IndexesOf(hidden_word, letter);
		wordsManager->Filter(filtered, letter, indexes); //update filtered by letter with indexes
	}
	return filtered;
}

void CpuWordGuesser::FillterByAnswerAndLetter(char letter, char ans)
{
	if (ans == 'y')
	{
		std::vector<int> indexes = IndexesOf(hidden_word, letter);
		wordsManager->Filter(Helpers::current_game_words, letter, indexes); //update filtered by letter with indexes
	}
	else
	{
		wordsManager->FilterByMissingChar(Helpers::current_game_words, letter);
	}
	AddLetterToUsed(letter);
}

char CpuWordGuesser::SuggestLetter1() //50/50
{
	if (Helpers::current_game_words.size() == 0)
	{
		for (char letter : Helpers::orderedLettersByFrequencry)
		{
			if (this->used_letters.find(letter) == this->used_letters.end())
			{
				return letter;
			}
		}
	}
	else
	{
		std::vector<int> averageUsedLetters;
		averageUsedLetters = wordsManager->GetLettersOccurancesPercents(Helpers::current_game_words, used_letters);
		//not ordered

		int minimalDiffIndex = 0;

		for (int i = 0; i < averageUsedLetters.size(); ++i)
		{
			if (this->used_letters.find(i + 97) == this->used_letters.end())
			{
				minimalDiffIndex = i;
				break;
			}
		}
		for (int i = 1; i < averageUsedLetters.size(); ++i)
		{
			if (this->used_letters.find(i + 97) == this->used_letters.end() && 50 - averageUsedLetters[i] < 50 -
				averageUsedLetters[
					minimalDiffIndex])
			{
				minimalDiffIndex = i;
			}
		}

		return minimalDiffIndex + 97;
	}
}

char CpuWordGuesser::SuggestLetter2()
{
	return wordsManager->GetMostCommonLetter(Helpers::current_game_words, used_letters);
}
