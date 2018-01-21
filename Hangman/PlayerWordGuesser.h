#pragma once
#include <string>
#include "GameLevel.h"
#include <vector>
#include "Guesser.h"

class PlayerWordGuesser : public Guesser
{
public:
	PlayerWordGuesser(std::string word, GameLevel game_level = GameLevel::Easy);
	~PlayerWordGuesser();

	void Initialize(GameLevel level);
	void Guess(char c);
	void DisplayHiddenWord();
	void DisplayUsedLetters();
	

private:
	GameLevel game_level;
	std::string word;

};
