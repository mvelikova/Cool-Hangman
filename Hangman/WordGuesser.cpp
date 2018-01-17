#include "WordGuesser.h"
#include "Constants.h"
#include <iostream>


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

void WordGuesser::Initialize()
{
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
	if (this->hidden_word.find(c) != std::string::npos)
	{
		mistakes++;
		return;
	}
	bool isFound = false;
	std::vector<int> charLocation = IndexesOf(this->word, c);

	//find all occurances of this char and update hidden word
	for (int i = 0; i < charLocation.size(); i++)
	{
		isFound = true;
		this->hidden_word[charLocation[i]] = c;
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

bool WordGuesser::WordIsGuessed()
{
	if (this->hidden_word.find('_') == std::string::npos)
	{
		return true;
	}
	return false;
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
