#pragma once
#include <set>
#include <vector>

class Helpers
{
public:
	Helpers();
	~Helpers();

	static std::set<std::string> all_words;
	static std::set<std::string> current_game_words;
	 
	static void DrawCursor(int index, int indexes, int delimiters = 0);
};
