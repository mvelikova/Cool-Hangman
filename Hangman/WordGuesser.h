#pragma once
#include <string>
#include "GameLevel.h"
#include <vector>
#include "Guesser.h"

class WordGuesser:Guesser
{
public:
	WordGuesser(std::string word, GameLevel game_level = GameLevel::Easy);
	~WordGuesser();
	void Initialize(GameLevel level);
	void Guess(char c);
	int GetMistakes() const;
	std::string GetHiddenWord();
	void DisplayHiddenWord();
	void DisplayUsedLetters();
		bool WordIsGuessed();
	bool AllMistakesAreMade();
	std::vector<int> IndexesOf(std::string word, char a);
	std::string word;


private:
	int mistakes;
	GameLevel game_level;
};
