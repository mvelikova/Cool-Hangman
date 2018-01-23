#pragma once
#include <set>
#include <vector>
#include <map>

class Helpers
{
public:
	Helpers();
	~Helpers();

	static std::map<size_t, std::set<std::string>> all_words;
	static std::set<std::string> current_game_words;
	static std::string orderedLettersByFrequencry;

	static void DrawCursor(int index, int indexes, int delimiters = 0);
};
