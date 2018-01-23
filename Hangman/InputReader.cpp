#include "InputReader.h"
#include <fstream>
#include <set>
#include <iostream>
#include <map>
#include <string>
#include "Helpers.h"

InputReader::InputReader(std::ifstream& istream) : ifs(istream)
{
}

InputReader::~InputReader()
{
}

WordsBySize InputReader::ReadAll(WordsBySize& result) const
{
	std::cout << "STARTING" << std::endl; // debug

	std::string word;
	while (ifs >> word)
	{
		size_t word_size = word.size();

		if (result.find(word_size) == result.end())
		{
			//not found, then create
			std::set<std::string> newSet;
			result.insert(std::pair<size_t, std::set<std::string>>(word_size, newSet));
		}

		result[word_size].insert(word);
	}

	return result;
}
