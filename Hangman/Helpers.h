#pragma once
#include <set>

class Helpers
{
public:
	Helpers();
	~Helpers();

	static std::set<std::string> all_words;

	static void DrawCursor(int index, int indexes, int delimiters = 0);
};
