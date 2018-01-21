#pragma once
#include "BaseGame.h"
#include "PlayerWordGuesser.h"

class PlayerGame : public BaseGame
{
public:
	PlayerGame(GameLevel game_level);
	~PlayerGame();

	virtual void Run() override;
	virtual void Draw() override;
	std::string ChooseWord();
	virtual void Turn() override;
protected:
	void EndGame() override;

private:
	PlayerWordGuesser* guesser;
	PlayerGame();
};
