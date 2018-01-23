#include "Helpers.h"
#include <iostream>
#include <map>
#include "WordsManager.h"

Helpers::Helpers()
{
}


Helpers::~Helpers()
{
}

/**
 * \brief Draws a cursor like this "^" under array elements with "indexes" element count at index = "index" with "delimiters" spaces between
 * \param index 
 * \param indexes 
 * \param delimiters 
 */
void Helpers::DrawCursor(int index, int indexes, int delimiters)
{
	std::string delimiter(delimiters, ' ');

	for (int i = 0; i < indexes; ++i)
	{
		(i == index) ? std::cout << "^" : std::cout << delimiter.c_str() << " ";
	}
	std::cout << std::endl;
}

WordsBySize WordsManager::all_words;
std::set<std::string> WordsManager::current_game_words;
std::string WordsManager::orderedLettersByFrequencry = "etaoinshrdlcumwfgypbvkjxqz";
