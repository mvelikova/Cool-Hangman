#pragma once
#include "IRunnable.h"
#include <ctime>
#include "IDrawable.h"
#include "GameLevel.h"

class BaseGame : public IRunnable, public IDrawable
{
public:
	virtual ~BaseGame();

protected:
	BaseGame();

	int points;
	GameLevel level;
	double secondsElapsed;
	clock_t begin;
	clock_t end;

	void Run() override;
	void Draw() override = 0;
	virtual void EndGame();

private:
	virtual GameLevel PickLevel();
	virtual void PrintLevels(const int current_selection);
};
