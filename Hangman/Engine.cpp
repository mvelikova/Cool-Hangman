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

	Console::SetSize(CONSOLE_WIDTH, CONSOLE_HEIGHT);
	while (true)
	{
		GameMenu* menu = new GameMenu(new GameStarter());
		menu->Run();
		Console::SetCursorPosition(0,45);
		std::cout << "Press ENTER to play again and ESC to end the game" << std::endl;
		char ans;
		ans = Console::ReadKey();

		while (ans != ENTER && ans != ESCAPE)
		{
			ans = Console::ReadKey();
		}
		if (ans == ESCAPE)
		{
			Console::Clear();
			break;
		}
	}


	delete reader;
}
