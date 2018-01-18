#pragma once
#include <string>
#include <vector>
class Guesser
{
protected:
	std::string hidden_word;
	std::vector <char> used_letters;
		Guesser();
	~Guesser();
};

