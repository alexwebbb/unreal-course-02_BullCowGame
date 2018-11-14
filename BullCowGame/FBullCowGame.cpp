#include "FBullCowGame.h"
#include <algorithm>
#include <string>

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	bMyGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

FString FBullCowGame::NormalizeGuess(FString Guess) const
{
	int len = Guess.length();
	FString LowerCaseGuess = Guess;

	// Convert the string to lower case letters 
	for (int i = 0; i < len; i++)
	{
		LowerCaseGuess[i] = tolower(Guess[i]);
	}

	return LowerCaseGuess;
}

bool FBullCowGame::IsGameWon() const
{
	return bMyGameIsWon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// check if a given string is isogram or not 
	int len = Guess.length();
	FString SortedGuess = Guess;

	std::sort(SortedGuess.begin(), SortedGuess.end());
	for (int i = 0; i < len; i++)
	{
		if (SortedGuess[i] == SortedGuess[i + 1])
			return EWordStatus::Not_Isogram;
	}

	// check if wrong length
	if (Guess.length() != GetHiddenWordLength())
	{
	return EWordStatus::Wrong_Length;
	}

	// otherwise
	return EWordStatus::OK;

}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{

	// increment turn
	MyCurrentTry++;

	// set retunr variable
	FBullCowCount BullCowCount;


	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compares letters against the word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (MyHiddenWord[i] == Guess[j])
			{
				// if they match them
				if (i == j)
				{
					// increment bulls if they are in the same place
					BullCowCount.Bulls++;
				}
				else
				{
					// increment cows if not
					BullCowCount.Cows++;
				}

			}

		}
	}

	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bMyGameIsWon = true;
	}

	return BullCowCount;
}
