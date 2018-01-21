#include "WordsManager.h"
#include "Helpers.h"

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

std::vector<int> WordsManager::GetLettersOccurancesPercents(const std::set<std::string>& words, std::set<char> used_letters)
{
	const int lowercase_offset = 97;
	const int english_alphabet_size = 26;
	double characterOccurances[english_alphabet_size] = {0};

//	for (auto word : words)
//	{
//		for (auto character : word)
//		{
//			int idx = character - lowercase_offset;
//			characterOccurances[idx]++;
//		}
//	}
	for (int j=0;j<26;j++)
	{
		for (auto word : words)
		{
			if (word.find(j+lowercase_offset) != std::string::npos)
			{
				characterOccurances[j]++;
			}
		}
	}
	for (auto le : used_letters)
	{
		characterOccurances[le - lowercase_offset] = 0;
	}
	int sum = 0;
	for (int i = 0; i < english_alphabet_size; ++i)
	{
		sum += characterOccurances[i];
	}
//	double percentOfSum = 100.0 / sum;
	int smallestDiffIndex = 0;

	for (int i = 0; i < english_alphabet_size; ++i)
	{
		characterOccurances[i] = (characterOccurances[i] * 100) / Helpers::current_game_words.size();
	}
	std::vector<int> res(characterOccurances,
	                     characterOccurances + sizeof characterOccurances / sizeof characterOccurances[0]);
	return res;
}

char WordsManager::GetMostCommonLetter(const std::set<std::string>& words, std::set<char> used_letters)
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

	char maxLetterIdx;
	for (int i = 0; i < english_alphabet_size; ++i)
	{
		if (used_letters.find(i+lowercase_offset)==used_letters.end())
		{
			maxLetterIdx = i;
			break;
		}
	}

	for (int i = maxLetterIdx+1; i < english_alphabet_size; ++i)
	{
		if (characterOccurances[i] > characterOccurances[maxLetterIdx] && used_letters.find(i + lowercase_offset) == used_letters.end())
		{
			maxLetterIdx = i;
		}
	}

	return maxLetterIdx + lowercase_offset;
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
		int letterCount = 0;
		for (int i=0;i<word.size();i++)
		{
			if (word[i]==a)
			{
				letterCount++;
			}
		}
		if (letterCount!=charPositions.size())
		{
			allMatch = false;
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
