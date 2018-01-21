#include "Guesser.h"
#include "Constants.h"


Guesser::Guesser()
{
}


Guesser::~Guesser()
{
}
int Guesser::GetMistakes() const
{
	return this->mistakes;
}


bool Guesser::AllMistakesAreMade()
{
	if (mistakes <= ACCEPTABLE_ERRORS)
	{
		return false;
	}
	return true;
}
std::string Guesser::GetHiddenWord()
{
	return this->hidden_word;
}
/**
* \brief Gets the index locations of a character inside a word
* \param word
* \param a
* \return
*/
std::vector<int> Guesser::IndexesOf(std::string word, char a)
{
	std::vector<int> indexes;

	for (int i = 0; i < word.size(); i++)
		if (word[i] == a)
			indexes.push_back(i);

	return indexes;
}

bool Guesser::WordIsGuessed()
{
	if (this->hidden_word.find('_') == std::string::npos)
	{
		return true;
	}
	return false;
}

void Guesser::addMistake()
{
	this->mistakes++;
}


