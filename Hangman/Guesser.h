#pragma once
#include <string>
#include <vector>
#include <set>

class Guesser
{
public:

	 int GetMistakes() const;

	 bool AllMistakesAreMade();
	 bool WordIsGuessed();
	 
	 void addMistake();

	 std::string GetHiddenWord();
	 std::vector<int> IndexesOf(std::string word, char a);

protected:
	std::string hidden_word;
	std::set<char> used_letters;
	int mistakes;

	Guesser();
	~Guesser();
};
