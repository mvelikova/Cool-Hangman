#pragma once
#include <vector>
#include <string>

class InputReader
{
private:
	std::ifstream& ifs;
public:
	InputReader(std::ifstream& istream);
	~InputReader();
	std::vector<std::string> WriteAll() const;
};
