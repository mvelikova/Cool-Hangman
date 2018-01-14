#pragma once
#include <vector>

class StatisticsManager
{
public:
	StatisticsManager();
	~StatisticsManager();
	char Get50percentUsedLetter(const std::vector<std::string>& words);
	char GetMostCommonLetter(const std::vector<std::string>& words);

};
