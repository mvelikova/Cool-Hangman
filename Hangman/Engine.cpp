#include "Engine.h"
#include <fstream>
#include <iostream>
#include "InputReader.h"
#include "Constants.h"
#include <thread>
#include <future>
#include "GameMenu.h"
#include "WordsManager.h"
#include "Helpers.h"


Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::Run()
{
	std::string path = "..\\" + Constants::DictionaryFilePath;
	std::ifstream ifs(path);
	InputReader* reader = new InputReader(ifs);

	auto f = std::async(std::launch::async, &InputReader::WriteAll, reader);
	Helpers::all_words = f.get();

	std::cout << "Starting..." << std::endl;

	GameMenu* menu = new GameMenu(new GameStarter());
	menu->Run();

	delete reader;
}
