#include "InputReader.h"
#include <fstream>

InputReader::InputReader(std::ifstream& istream) : ifs(istream)
{
}

InputReader::~InputReader()
{
}

std::vector<std::string> InputReader::WriteAll() const
{
	std::vector<std::string> result;

	std::string word;
	while (ifs >> word)
	{
		result.push_back(word);
	}

	return result;
}
