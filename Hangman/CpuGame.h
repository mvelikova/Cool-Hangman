#pragma once
#include "BaseGame.h"
#include <set>

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

	std::string hidden_word;
	std::set<std::string> used_letters;

	void RunLevelLogic();
	void GiveStartingLetters();
	void SetCommonLetterInHiddenWord(char letter);
	void DrawWordGuesser(int index) const;
};

