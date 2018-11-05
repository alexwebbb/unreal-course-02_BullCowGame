#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool PromptToReplay();
string GetGuess();
constexpr int WORD_LENGTH = 9;
constexpr int NUM_OF_TURNS = 3;


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
	cout << "Welcome to Bulls and Cows! Its a word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter word I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	string Guess = "";
	for (int i = 0; i < NUM_OF_TURNS; i++)
	{
		Guess = GetGuess();
		// repeat the guess back to user
		cout << "Your guess is " << Guess << ".\n";
		cout << endl;
	}
}

bool PromptToReplay()
{
	cout << "Play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	cout << endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}


string GetGuess()
{
	cout << "Please enter your guess: ";
	// get guess from user
	string Guess = "";
	getline(cin, Guess);
	cout << endl;

	return Guess;
}