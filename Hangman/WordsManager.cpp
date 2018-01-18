#include "WordsManager.h"

WordsManager::WordsManager()
{
}

WordsManager::~WordsManager()
{
}

/**
 * \brief Deletes all words containing a character.
 * \param words 
 * \param a 
 * \return 
 */
void WordsManager::FilterByMissingChar(std::set<std::string>& words, char a)
{
	std::set<std::string> result;

	for (auto word : words)
	{
		bool foundChar = false;

		for (auto ch : word)
		{
			if (ch == a)
			{
				foundChar = true;
				break;
			}
		}
		//erase
		if (foundChar == false)
		{
			result.insert(word);
		}
	}
	words = result;
}

std::vector<int> WordsManager::GetOrderedLettersCloseTo50Percent(const std::set<std::string>& words)
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
	int sum = 0;
	for (int i = 0; i < english_alphabet_size; ++i)
	{
		sum += characterOccurances[i];
	}
	double percentOfSum = 100.0 / sum;
	int smallestDiffIndex = 0;

	for (int i = 0; i < english_alphabet_size; ++i)
	{
		characterOccurances[i] *= percentOfSum;
	}
	std::vector<int> res(characterOccurances,
	                     characterOccurances + sizeof characterOccurances / sizeof characterOccurances[0]);
	return res;
}

char WordsManager::GetMostCommonLetter(const std::set<std::string>& words)
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

void WordsManager::Filter(std::set<std::string>& words, char a, std::vector<int> charPositions)
{
	std::set<std::string> result;

	for (auto word : words)
	{
		bool allMatch = true;
		for (int i = 0; i < charPositions.size(); ++i)
		{
			if (word[charPositions[i]] != a)
			{
				allMatch = false;
				break;
			}
		}
		if (allMatch)
		{
			result.insert(word);
		}
	}
	words = result;
}

/**
 * \brief Filters words by size
 * \param words 
 * \param size 
 * \return 
 */
std::set<std::string> WordsManager::Filter(const std::set<std::string>& words, unsigned int size)
{
	std::set<std::string> result;

	for (auto word : words)
	{
		if (word.size() == size)
		{
			result.insert(word);
		}
	}

	return result;
}
