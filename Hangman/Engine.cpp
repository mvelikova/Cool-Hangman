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
#include "Console.h"
#include "Messages.h"


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

	auto f = std::async(std::launch::async, &InputReader::ReadAll, reader);
	Helpers::all_words = f.get();

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

	delete reader;
}
