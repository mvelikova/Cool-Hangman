#pragma once
#include <vector>

class StatisticsManager
{
public:
	StatisticsManager();
	~StatisticsManager();

	char GetMostCommonLetter(const std::vector<std::string>& words);
};
