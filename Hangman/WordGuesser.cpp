#include "WordGuesser.h"
#include "Constants.h"
#include <iostream>
#include <algorithm>

WordGuesser::WordGuesser(std::string word, GameLevel game_level)
{
	this->word = word;
	this->game_level = game_level;
	std::string hidden(word.size(), WORD_GUESSER_HIDDEN_CHAR);
	this->hidden_word = hidden;
	this->mistakes = 0;
}


WordGuesser::~WordGuesser()
{
}

void WordGuesser::Initialize(GameLevel level)
{
	this->game_level = level;
	char firstLetter = this->word[0];
	char lastLetter = this->word[this->word.size() - 1];

	switch (this->game_level)
	{
	case Easy:
		Guess(firstLetter);
		Guess(lastLetter);
		mistakes = 0;
		break;
	case Advanced:
		Guess(firstLetter);
		break;
	case Pro:
	default:
		break;
	}
}

void WordGuesser::Guess(char c)
{
	if (std::find(this->used_letters.begin(), this->used_letters.end(), c) != this->used_letters.end())
	{
		//if found
		return;
	}

	this->used_letters.insert(c);
	
	bool isFound = false;
	std::vector<int> charLocations = IndexesOf(this->word, c);

	//find all occurances of this char and update hidden word
	for (int i = 0; i < charLocations.size(); i++)
	{
		isFound = true;
		this->hidden_word[charLocations[i]] = c;
	}
	
	if (!isFound)
	{
		mistakes++;
	}
}


int WordGuesser::GetMistakes() const
{
	return this->mistakes;
}

std::string WordGuesser::GetHiddenWord()
{
	return this->hidden_word;
}

void WordGuesser::DisplayHiddenWord()
{
	std::cout << hidden_word[0];
	for (int i = 1; i < hidden_word.size(); i++)
	{
		std::cout << " " << hidden_word[i];
	}
	std::cout << std::endl;
}

void WordGuesser::DisplayUsedLetters()
{
	std::cout << "Used letters: ";

	for (auto used_letter : this->used_letters)
	{
		std::cout << used_letter << ", ";
	}

	std::cout << std::endl;
}

bool WordGuesser::WordIsGuessed()
{
	if (this->hidden_word.find('_') == std::string::npos)
	{
		return true;
	}
	return false;
}

bool WordGuesser::AllMistakesAreMade()
{
	if (mistakes <= ACCEPTABLE_ERRORS)
	{
		return false;
	}
	return true;
}

/**
 * \brief Gets the index locations of a character inside a word
 * \param word 
 * \param a 
 * \return 
 */
std::vector<int> WordGuesser::IndexesOf(std::string word, char a)
{
	std::vector<int> indexes;

	for (int i = 0; i < word.size(); i++)
		if (word[i] == a)
			indexes.push_back(i);

	return indexes;
}
