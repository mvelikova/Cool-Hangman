#pragma once
#include <string>
#include <vector>
#include <set>

class Guesser
{
protected:
	std::string hidden_word;
	std::set<char> used_letters;

	Guesser();
	~Guesser();
};
