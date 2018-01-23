#pragma once
#include <string>
#include <set>
#include <map>

class InputReader
{
private:
	std::ifstream& ifs;
public:
	InputReader(std::ifstream& istream);
	~InputReader();
	std::map<size_t, std::set<std::string>> ReadAll() const;
};
