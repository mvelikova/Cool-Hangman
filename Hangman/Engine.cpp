#include "Engine.h"
#include <fstream>
#include <iostream>
#include "InputReader.h"
#include "Constants.h"
#include <thread>
#include <future>
#include "GameMenu.h"
#include "Helpers.h"
#include "Console.h"
#include "Messages.h"
#include "WordsManager.h"


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

	std::future<WordsBySize> f = std::async(std::launch::async, [&reader] { return reader->ReadAll(WordsManager::all_words); });

	Console::SetSize(CONSOLE_WIDTH, CONSOLE_HEIGHT);

	while (true)
	{
		GameMenu* menu = new GameMenu(new GameStarter());
		menu->Run();

		Console::SetCursorPosition(0, 45);
		std::cout << Messages::EnterToPlayEscToEnd << std::endl;

		char c;
		c = Console::ReadKey();

		while (c != ENTER && c != ESCAPE)
		{
			c = Console::ReadKey();
		}

		if (c == ESCAPE)
		{
			Console::Clear();
			delete menu;
			break;
		}
	}

	//await the thread in order to not get its destructor called very early
	//and in order to synchronize all threads before 
	//which would've led to a synchronous-like behaviour
	f.get();

	delete reader;
}
