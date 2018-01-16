#pragma once
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

#define WORD_GUESSER_HIDDEN_CHAR '_'
#define ACCEPTABLE_ERRORS 8

class Constants
{
public:
	static const std::string DictionaryFilePath;
private:
	// Disallow creating an instance of this object
	Constants() {}
};

