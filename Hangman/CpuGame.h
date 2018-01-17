#pragma once
#include "BaseGame.h"

class CpuGame : public BaseGame, public IDrawable
{
public:
	CpuGame(GameLevel game_level);
	~CpuGame();

	virtual void Run() override;
	virtual void Draw() override;

protected:
	void EndGame() override;

private:
	CpuGame();
};

