#include "FBullCowGame.h"
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
	return;
}

int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	// if guess is not an isogram
	if (false)
	{

	}
	// if guess is not lowercase
	else if (false)
	{

	}
	// wrong length
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EWordStatus::Wrong_Length;
	}
	// otherwise
	return EWordStatus::OK; // TODO set error codes
	
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
				else {
					// increment cows if not
					BullCowCount.Cows++;
				}

			}

		}
	}
	return BullCowCount;
}
