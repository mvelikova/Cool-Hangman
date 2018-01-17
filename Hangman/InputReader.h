#pragma once
#include <string>
#include <set>

class InputReader
{
private:
	std::ifstream& ifs;
public:
	InputReader(std::ifstream& istream);
	~InputReader();
	std::set<std::string> WriteAll() const;
};
