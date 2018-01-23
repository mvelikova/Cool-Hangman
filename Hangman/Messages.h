#pragma once
#include <string>

class Messages
{
public:
	Messages();
	~Messages();

	static const std::string EnterLetter;
	static const std::string YouWon;
	static const std::string WordWas;
	static const std::string EnterToPlayEscToEnd;
	static const std::string NavigationControls;
	static const std::string GiveTheSizeOfTheWord;
	static const std::string CpuWon;
	static const std::string CpuLost;
	static const std::string PressYorN;
	static const std::string WhatsTheFirstLetter;
	static const std::string WhatsTheLastLetter;
	static const std::string LoganMessage;
	static const std::string WhatWasTheWord;

	static const std::string GameMenuOption1;
	static const std::string GameMenuOption2;
	static const std::string CpuGuessedNonExistentWord;
};
