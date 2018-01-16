#include "WordGuesser.h"
#include "Constants.h"


WordGuesser::WordGuesser(std::string word, GameLevel game_level)
{
	this->word = word;
	this->game_level = game_level;

	std::string hidden(word.size(), WORD_GUESSER_HIDDEN_CHAR);
	this->hidden_word = hidden;
}


WordGuesser::~WordGuesser()
{
}

void WordGuesser::Guess(char c)
{
	bool isFound = false;
	std::size_t found = this->word.find(c);

	//find all occurances of this char and update hidden word
	while (found != std::string::npos)
	{
		isFound = true;
		this->hidden_word[found] = c;

		found = this->word.find(c);
	}

	if (!found)
	{
		mistakes++;
	}
}

int WordGuesser::GetMistakes() const
{
	return this->mistakes;
}
