#pragma once
#include <ostream>

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
		case Easy: lhs << "Easy";
			break;
		case Advanced: lhs << "Advanced";
			break;
		case Pro: lhs << "Pro";
			break;
	}
	return lhs;
}
