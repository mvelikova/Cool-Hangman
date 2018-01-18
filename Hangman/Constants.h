#pragma once
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESCAPE 27

#define WORD_GUESSER_HIDDEN_CHAR '_'
#define ACCEPTABLE_ERRORS 6

#define CONSOLE_WIDTH 100
#define CONSOLE_HEIGHT 60

#define GAME_TITLE "Cool hangman"

class Constants
{
public:
	static const std::string DictionaryFilePath;
	static const std::vector<std::string> HangmanHead;
	static const std::vector<std::string> HangmanHands;
	static const std::vector<std::string> HangmanLegs;
	static const std::vector<std::string> Gibbet1;
	static const std::vector<std::string> Gibbet2;
	static const std::vector<std::string> Gibbet3;
	static const std::vector<std::string> Gibbet4;


private:
	// Disallow creating an instance of this object
	Constants() {}
};

