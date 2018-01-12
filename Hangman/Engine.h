#pragma once
#include <string>
#include <vector>

class Engine
{
public:
	Engine();
	~Engine();
	void Run();



private:
	std::vector<std::string> words;

	void ReadWordsFromFile();
};

