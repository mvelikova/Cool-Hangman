#pragma once
#include <set>
#include <vector>
#include <map>

typedef std::map<size_t, std::set<std::string>> WordsBySize;

class Helpers
{
public:
	Helpers();
	~Helpers();

	static void DrawCursor(int index, int indexes, int delimiters = 0);
};
