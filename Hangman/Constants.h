#pragma once
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESCAPE 27
#define SPACE 32

#define WORD_GUESSER_HIDDEN_CHAR '_'
#define ACCEPTABLE_ERRORS 6

#define CONSOLE_WIDTH 200
#define CONSOLE_HEIGHT 60

#define GAME_TITLE "Cool hangman"
#define GAME_LEVEL_1 "Easy"
#define GAME_LEVEL_2 "Advanced"
#define GAME_LEVEL_3 "Pro"

#define HANGMAN_DRAWING_START_Y 40

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

	static const std::vector<std::string> HangmanTitleDrawing;
	static const std::vector<std::string> Logan;

private:
	// Disallow creating an instance of this object
	Constants() {}
};

