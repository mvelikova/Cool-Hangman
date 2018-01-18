#pragma once
#include <string>
#include "GameLevel.h"
#include <vector>
#include "Guesser.h"

class WordGuesser : Guesser
{
public:
	WordGuesser(std::string word, GameLevel game_level = GameLevel::Easy);
	~WordGuesser();

	void Initialize(GameLevel level);
	void Guess(char c);
	void DisplayHiddenWord();
	void DisplayUsedLetters();

	int GetMistakes() const;
	std::string GetHiddenWord();
	
	bool WordIsGuessed();
	bool AllMistakesAreMade();

	std::vector<int> IndexesOf(std::string word, char a);
	std::string word;

private:
	int mistakes;
	GameLevel game_level;
};
