#pragma once
#include "Guesser.h"
#include "WordsManager.h"

class CpuWordGuesser : public Guesser
{
public:
	CpuWordGuesser();
	~CpuWordGuesser();

	void SetLetterInHiddenWord(int pos, char letter);
	void AddLetterToUsed(char letter);
	void SetHiddenWord(std::string word);

	std::set<std::string> FilterBySizeAndLetters();
	void FillterByAnswerAndLetter(char letter, char ans);


	char SuggestLetter1(); //suggest a letter 50/50
	char SuggestLetter2(); //suggest most common letter

	private:
	WordsManager* wordsManager;
};
