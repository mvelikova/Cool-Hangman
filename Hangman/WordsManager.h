#pragma once
#include <string>
#include <vector>
#include <set>
#include "Helpers.h"

class WordsManager
{
public:
	WordsManager();
	~WordsManager();

	static WordsBySize all_words;
	static std::set<std::string> current_game_words;
	static std::string orderedLettersByFrequencry;

	void Filter(std::set<std::string>& words, char a, std::vector<int> charPositions);
	std::set<std::string> Filter(const std::set<std::string>& words, unsigned int size);
	void FilterByMissingChar(std::set<std::string>& words, char a);

	std::vector<int> GetLettersOccurancesPercents(const std::set<std::string>& words, std::set<char> used_letters);
	char GetMostCommonLetter(const std::set<std::string>& words, std::set<char> used_letters);
};

