#pragma once
#include "BaseGame.h"

class CpuGame : public BaseGame, public IDrawable
{
public:
	CpuGame();
	~CpuGame();

	void Run() override;
	void Draw() override;

protected:
	void EndGame() override;
};

