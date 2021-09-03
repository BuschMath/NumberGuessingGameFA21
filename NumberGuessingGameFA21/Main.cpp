#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int totalGuesses = 3;
int lb = 1;
int ub = 10;
int rNum;

void WelcText();
int CreateRnNum();
void SGText();		// Start guessing text
bool Guesses();		// Returns outcome of guessing
void WText();
void LText();

int main()
{
	WelcText();
	rNum = CreateRnNum();
	SGText();

	if (Guesses())
		WText();
	else
		LText();

	return 0;
}

void WelcText()
{
	cout << "Welcome to the number guessing game.\n\n";
	cout << "You will have " << totalGuesses << " to guess the correct number.";
	cout << "\n\nThe number is between" << lb << " and " << ub << endl << endl;
}

int CreateRnNum()
{
	cout << "Creating random number...\n\n";
	srand(time(NULL));
	return rand() % ub + lb;
}

void SGText()
{
	cout << "Random number created. You will have " << totalGuesses;
	cout << " guesses." << endl;
	cout << "Your guesses should be between " << lb << " and " << ub << endl;
}

// I need to work on this function definition.
// I should create another function for evaluating and not have numbers
// in text but in variables.
bool Guesses()
{
	cout << "Take your first guess: ";
	int gNum;
	cin >> gNum;
	
	if (gNum == rNum)
		return true;
	else
	{
		cout << "\n\nIncorrect, take your second guess: ";
		cin >> gNum;
	}

	if (gNum == rNum)
		return true;
	else
	{
		cout << "\n\nIncorrect, take your third guess: ";
		cin >> gNum;
	}

	return gNum == rNum;
}

void WText()
{
	cout << "\n\n You won!";
}

void LText()
{
	cout << "\n\n You lost!";
}
