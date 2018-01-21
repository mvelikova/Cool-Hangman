#include "PlayerWordGuesser.h"
#include "Constants.h"
#include <iostream>
#include <algorithm>

PlayerWordGuesser::PlayerWordGuesser(std::string word, GameLevel game_level)
{
	this->word = word;
	this->game_level = game_level;
	std::string hidden(word.size(), WORD_GUESSER_HIDDEN_CHAR);
	this->hidden_word = hidden;
	this->mistakes = 0;
}


PlayerWordGuesser::~PlayerWordGuesser()
{
}

void PlayerWordGuesser::Initialize(GameLevel level)
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

void PlayerWordGuesser::Guess(char c)
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





void PlayerWordGuesser::DisplayHiddenWord()
{
	std::cout << hidden_word[0];
	for (int i = 1; i < hidden_word.size(); i++)
	{
		std::cout << " " << hidden_word[i];
	}
	std::cout << std::endl;
}

void PlayerWordGuesser::DisplayUsedLetters()
{
	std::cout << "Used letters: ";

	for (auto used_letter : this->used_letters)
	{
		std::cout << used_letter << ", ";
	}

	std::cout << std::endl;
}
