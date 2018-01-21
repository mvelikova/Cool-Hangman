#pragma once
#include "BaseGame.h"
#include <set>
#include "CpuWordGuesser.h"

class CpuGame : public BaseGame, public IDrawable
{
public:
	CpuGame(GameLevel game_level);
	virtual ~CpuGame();

	virtual void Run() override;
	virtual void Draw() override;
	virtual void Turn() override;

protected:
	void EndGame() override;

private:
	CpuGame();

	CpuWordGuesser* guesser;

	
	void RunLevelLogic();
	void GiveStartingLetters();
	void SetCommonLetterInHiddenWord(char letter);
	void DrawPlayerWordGuesser(int index) const;

	bool GameShouldEnd();
};

