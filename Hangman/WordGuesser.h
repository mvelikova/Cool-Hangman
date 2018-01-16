#pragma once
#include <string>
#include "GameLevel.h"

class WordGuesser
{
public:
	WordGuesser(std::string word = "", GameLevel game_level = GameLevel::Easy);
	~WordGuesser();

	void Guess(char c);
	int GetMistakes() const;
private:
	int mistakes;
	std::string word;
	std::string hidden_word;
	GameLevel game_level;
};
