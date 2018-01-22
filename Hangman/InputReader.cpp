#include "InputReader.h"
#include <fstream>
#include <set>
#include <iostream>

InputReader::InputReader(std::ifstream& istream) : ifs(istream)
{
}

InputReader::~InputReader()
{
}

std::set<std::string> InputReader::ReadAll() const
{
	std::cout << "STARTING" << std::endl; // debug

	std::set<std::string> result;

	std::string word;
	while (ifs >> word)
	{
		result.insert(word);
	}

	return result;
}
