#pragma once
#include "IDrawable.h"
#include <string>
#include <vector>
#include "GameStarter.h"
#include "IRunnable.h"

class GameMenu : public IDrawable, public IRunnable
{
public:
	GameMenu(GameStarter* game_starter);
	~GameMenu();

	void Run() override;
	void Draw() override;

private:
	GameMenu();

	GameStarter* game_starter;
	std::vector<std::string> menu_options;
	void DrawMenuOptions(int selectedOption = 0);
};

