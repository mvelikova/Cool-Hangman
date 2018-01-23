#pragma once
#include <map>
#include "Helpers.h"

class InputReader
{
private:
	std::ifstream& ifs;
public:
	InputReader(std::ifstream& istream);
	~InputReader();
	WordsBySize ReadAll(WordsBySize& result) const;
};
