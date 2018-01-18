#pragma once
#include "BaseGame.h"

class PlayerGame : public BaseGame
{
public:
	PlayerGame( GameLevel game_level);
	~PlayerGame();

	virtual void Run() override;
	virtual void Draw() override;
		std::string ChooseWord();
	void Turn();
protected:
	void EndGame() override;

private:
	WordGuesser*guesser;
	PlayerGame();
};
