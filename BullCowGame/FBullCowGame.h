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

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Pending
};


class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	FString NormalizeGuess(FString) const;
	EWordStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	// counts bulls and cows and increments try number. assumes valid guess
	FBullCowCount SubmitGuess(FString);
	void Reset();
	
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bMyGameIsWon;
};

