#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
bool PromptToReplay();
FText GetGuess();
constexpr int32 WORD_LENGTH = 9;
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
	}
	while (bPlaying_Game);

}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Bulls and Cows! Its a word game.\n";
	// world length variable has no relationship with actual word length
	std::cout << "Can you guess the " << "6";
	std::cout << " letter word I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	const int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	for (int32 i = 0; i < MaxTries; i++)
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		Guess = GetGuess();
		// TODO validate guess
		// repeat the guess back to user
		std::cout << "Try " << CurrentTry << ". ";
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << ". ";
		std::cout << "Cows: " << BullCowCount.Cows << ".";
		std::cout << std::endl;
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


FText GetGuess()
{
	std::cout << "Please enter your guess: ";
	// get guess from user
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}