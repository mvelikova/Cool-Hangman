#pragma once
#include "IRunnable.h"
#include <ctime>
#include "IDrawable.h"
#include "GameLevel.h"
#include "WordGuesser.h"

class BaseGame : public IRunnable, public IDrawable
{
public:
	virtual ~BaseGame();
	virtual double get_current_seconds_elapsed();
	virtual void Run() override;

protected:
	BaseGame( GameLevel game_level = GameLevel::Easy);

	int points;
	GameLevel game_level;
	double secondsElapsed;
	clock_t begin;
	clock_t end;

	virtual void Draw() = 0;
	virtual void DrawHangman(int mistakes);
		virtual void EndGame();

private:
	virtual GameLevel PickLevel();
	virtual void PrintLevels(const int current_selection);
};
