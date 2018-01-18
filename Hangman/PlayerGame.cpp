#include "PlayerGame.h"
#include <iostream>
#include "Helpers.h"
#include "Console.h"
#include <windows.h>
#include "Constants.h"


PlayerGame::PlayerGame(GameLevel game_level) : BaseGame( game_level)
{
	std::string word = ChooseWord();
	guesser = new WordGuesser(word, this->game_level);

}


PlayerGame::~PlayerGame()
{
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
//	if (guesser->GetMistakes()==1)
//	{
//		int x = 10;
//		int y = 0;
//		for (auto line : Constants::HangmanHead)
//		{
//			Console::SetCursorPosition(x, y);
//			std::cout << line;
//			y++;
//		}
//		
//	}
		std::cout << std::endl;
	
}



std::string PlayerGame::ChooseWord()
{
	std::set<std::string> words = Helpers::all_words;
	int wordsCount = words.size();
	srand(time(NULL));
	int randomIndex= rand() % wordsCount;
	std::set<std::string>::const_iterator it(words.begin());

	advance(it, randomIndex);
	return *it;
}

void PlayerGame::Turn()
{
	this->Draw();
	std::cout << "Please enter a signle letter: ";
	char c;
	std::cin >> c;
	if (c>=65 && c<=90)
	{
		c += 32;
		guesser->Guess(c);

	}
	else if(c >= 97 && c <= 122)
	{
		guesser->Guess(c);
	}
	else
	{
		Turn();
	}
}

void PlayerGame::EndGame()
{
	BaseGame::EndGame();
}

PlayerGame::PlayerGame()
{
}
