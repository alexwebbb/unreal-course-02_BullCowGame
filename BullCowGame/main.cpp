#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool PromptToReplay();
FText GetValidGuess();
constexpr int32 NUM_OF_TURNS = 3;

FBullCowGame BCGame;


int main()
{
	bool bPlaying_Game = true;
	do
	{
		PrintIntro();
		PlayGame();
		bPlaying_Game = PromptToReplay();
		BCGame.Reset();
	}
	while (bPlaying_Game);

}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Bulls and Cows! Its a word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter word I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	const int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	for (int32 i = 0; i < MaxTries && !BCGame.IsGameWon(); i++)
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		Guess = GetValidGuess();
		// repeat the guess back to user
		std::cout << "Try " << CurrentTry << ". ";
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << ". ";
		std::cout << "Cows: " << BullCowCount.Cows << ".";
		std::cout << std::endl;
	}

	if (BCGame.IsGameWon())
	{
		std::cout << "You win! \\o/\n";
	}
	else
	{
		std::cout << "You lose...\n";
	}
}

bool PromptToReplay()
{
	std::cout << "Play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


FText GetValidGuess()
{

	std::cout << "Please enter your guess: ";
	EWordStatus Status = EWordStatus::Pending;
	FText Guess = "";
	do
	{
		// get guess from user
		std::getline(std::cin, Guess);
		Guess = BCGame.NormalizeGuess(Guess);
		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word with no repeated letters: ";
			break;
		case EWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word: ";
			break;
		default:
			Status = EWordStatus::OK;
		}
	}
	while (Status != EWordStatus::OK);

	return Guess;
}