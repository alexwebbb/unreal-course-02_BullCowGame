#include <iostream>
#include <string>

using namespace std;

int main()
{
	// introduce the game
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows! Its a word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter word I'm thinking of?\n";

	// get guess from user
	string Guess = "";
	cin >> Guess;

	// repeat the guess back to user
	cout << "Your guess is " << Guess << ".\n";

}