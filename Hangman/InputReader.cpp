#include "InputReader.h"
#include <fstream>
#include <set>

InputReader::InputReader(std::ifstream& istream) : ifs(istream)
{
}

InputReader::~InputReader()
{
}

std::set<std::string> InputReader::WriteAll() const
{
	std::set<std::string> result;

	std::string word;
	while (ifs >> word)
	{
		result.insert(word);
	}

	return result;
}
