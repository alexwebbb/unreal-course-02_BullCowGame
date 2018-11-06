#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
bool PromptToReplay();
std::string GetGuess();
constexpr int WORD_LENGTH = 9;
constexpr int NUM_OF_TURNS = 3;

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
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter word I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	const int MaxTries = BCGame.GetMaxTries();
	const int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	for (int i = 0; i < MaxTries; i++)
	{
		Guess = GetGuess();
		// repeat the guess back to user
		std::cout << "Try " << CurrentTry << ". ";
		std::cout << "Your guess is " << Guess << ".\n";
		std::cout << std::endl;
	}
}

bool PromptToReplay()
{
	std::cout << "Play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


std::string GetGuess()
{
	std::cout << "Please enter your guess: ";
	// get guess from user
	std::string Guess = "";
	std::getline(std::cin, Guess);
	std::cout << std::endl;

	return Guess;
}