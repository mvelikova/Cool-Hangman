#pragma once
#include "BaseGame.h"

class PlayerGame : public BaseGame
{
public:
	PlayerGame(std::string word, GameLevel game_level);
	~PlayerGame();

	virtual void Run() override;
	virtual void Draw() override;
	std::string ChooseWord();
protected:
	void EndGame() override;

private:
	PlayerGame();
};
