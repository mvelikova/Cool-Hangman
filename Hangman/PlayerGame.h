#pragma once
#include "BaseGame.h"

class PlayerGame : public BaseGame
{
public:
	PlayerGame();
	~PlayerGame();

	void Run() override;
	void Draw() override;

protected:
	void EndGame() override;
};

