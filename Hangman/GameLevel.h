#pragma once
#include <ostream>
#include "Constants.h"

//do not change this enum's int values
enum GameLevel
{
	Easy,
	Advanced,
	Pro
};

inline std::ostream& operator<<(std::ostream& lhs, GameLevel e)
{
	switch (e)
	{
	case Easy: lhs << GAME_LEVEL_1;
		break;
	case Advanced: lhs << GAME_LEVEL_2;
		break;
	case Pro: lhs << GAME_LEVEL_3;
		break;
	}
	return lhs;
}
