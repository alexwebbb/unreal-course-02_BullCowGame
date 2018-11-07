#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	FBullCowGame();

	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	// counts bulls and cows and increments try number. assumes valid guess
	FBullCowCount SubmitGuess(FString);
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};

