#pragma once
#include <string>
#include "GameLevel.h"
#include <vector>

class WordGuesser
{
public:
	WordGuesser(std::string word = "", GameLevel game_level = GameLevel::Easy);
	~WordGuesser();
	void Initialize();
	void Guess(char c);
	int GetMistakes() const;
	std::string GetHiddenWord();
	bool WordIsGuessed();
	std::vector<int> FindLocation(std::string,char);
private:
	int mistakes;
	std::string word;
	std::string hidden_word;
	GameLevel game_level;
};
