#include "PlayerGame.h"
#include <iostream>
#include "Helpers.h"
#include "Console.h"
#include <windows.h>
#include "Constants.h"
#include "PlayerWordGuesser.h"


PlayerGame::PlayerGame(GameLevel game_level) : BaseGame(game_level)
{
	std::string word = ChooseWord();
	guesser = new PlayerWordGuesser(word, this->game_level);
}


PlayerGame::~PlayerGame()
{
	delete guesser;
}

void PlayerGame::Run()
{
	BaseGame::Run();


	guesser->Initialize(this->game_level);

	while (!guesser->WordIsGuessed() && !guesser->AllMistakesAreMade())
	{
		Turn();
	}
	if (guesser->AllMistakesAreMade())
	{
		Draw();
	}
	else
	{
		Console::Clear();
		std::cout << "You WON!" << std::endl;
	}

	//game logic
}

void PlayerGame::Draw()
{
	Console::Clear();

	guesser->DisplayHiddenWord();
	guesser->DisplayUsedLetters();

	std::cout << guesser->word << std::endl; //TODO: make word private again
	std::cout << guesser->GetMistakes() << std::endl;

	DrawHangman(guesser->GetMistakes());
	Console::SetCursorPosition(0, 5);

	std::cout << std::endl;
}

std::string PlayerGame::ChooseWord()
{
	std::set<std::string> words = Helpers::all_words;
	int wordsCount = words.size();
	srand(time(NULL));
	int randomIndex = rand() % wordsCount;
	std::set<std::string>::const_iterator it(words.begin());

	advance(it, randomIndex);
	return *it;
}

void PlayerGame::Turn()
{
	this->Draw();
	std::cout << "Please enter a single letter: ";

	char c;
	c = Console::ReadKey();

	bool isUpper = c >= 65 && c <= 90;
	bool isLower = c >= 97 && c <= 122;

	while (!(isUpper || isLower)) // not a letter
	{
		std::cin >> c;

		this->Draw();
		std::cout << "Please enter a single letter: ";
	}

	if (isUpper)
	{
		//if upper
		c += 32;
	}

	guesser->Guess(c);
}

void PlayerGame::EndGame()
{
	BaseGame::EndGame();
}

PlayerGame::PlayerGame()
{
}
