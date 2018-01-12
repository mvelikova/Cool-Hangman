#include "Engine.h"
#include <fstream>
#include <iostream>
#include "InputReader.h"
#include "Constants.h"
#include <thread>
#include <future>
#include <chrono>
#include "StatisticsManager.h"


Engine::Engine()
{
	std::vector<std::string> w;
	this->words = w;
}


Engine::~Engine()
{
}

void Engine::Run()
{
	std::cout << "Start game" << std::endl;

	std::string path = "..\\" + Constants::DictionaryFilePath;
	std::ifstream ifs(path);

	InputReader* reader = new InputReader(ifs);

	auto f = std::async(std::launch::async, &InputReader::WriteAll, reader);

	std::vector<std::string> words = f.get();
	StatisticsManager sm;

	delete reader;
}
