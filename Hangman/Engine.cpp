#include "Engine.h"
#include <fstream>
#include <iostream>
#include "InputReader.h"
#include "Constants.h"
#include <thread>
#include <future>
#include "StatisticsManager.h"
#include "GameMenu.h"


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
	StatisticsManager sm;

	std::string path = "..\\" + Constants::DictionaryFilePath;
	std::ifstream ifs(path);
	InputReader* reader = new InputReader(ifs);

	auto f = std::async(std::launch::async, &InputReader::WriteAll, reader);
	std::vector<std::string> words = f.get();

	std::cout << "Starting..." << std::endl;
	GameMenu* menu = new GameMenu();
	menu->Run();

	delete reader;
}
