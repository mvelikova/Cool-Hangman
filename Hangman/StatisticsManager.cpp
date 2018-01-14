#include "StatisticsManager.h"
#include <iostream>


StatisticsManager::StatisticsManager()
{
}


StatisticsManager::~StatisticsManager()
{
}

char StatisticsManager::Get50percentUsedLetter(const std::vector<std::string>& words)
{
	const int lowercase_offset = 97;
	const int english_alphabet_size = 26;
	int characterOccurances[english_alphabet_size] = { 0 };

	for (auto word : words)
	{
		for (auto character : word)
		{
			int idx = character - lowercase_offset;
			characterOccurances[idx]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < english_alphabet_size; ++i)
	{
		sum += characterOccurances[i];
	}
	double percentOfSum = 100.0 / sum;
	int smallestDiffIndex = 0;
	for (int i = 1; i < english_alphabet_size; ++i)
	{
		if (50 - (characterOccurances[smallestDiffIndex] * percentOfSum)>50 - (characterOccurances[i] * percentOfSum))
		{
			smallestDiffIndex = i;
		}
	}
	return smallestDiffIndex + lowercase_offset;
}

char StatisticsManager::GetMostCommonLetter(const std::vector<std::string>& words)
{
	const int lowercase_offset = 97;
	const int english_alphabet_size = 26;

	int characterOccurances[english_alphabet_size] = {0};

	for (auto word : words)
	{
		for (auto character : word)
		{
			int idx = character - lowercase_offset;
			characterOccurances[idx]++;
		}
	}

	char maxLetter = 0;
	int v = characterOccurances[0];

	for (int i = 1; i < english_alphabet_size; ++i)
	{
		if (characterOccurances[i] > characterOccurances[maxLetter])
		{
			maxLetter = i;
		}
	}

	return maxLetter + lowercase_offset;
}
