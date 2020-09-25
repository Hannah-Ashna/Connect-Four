// The Source Code for the Connect Four Game - Console App Display

// Declaration of Headers
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

// Get Custom Header Files
#include "Player.h"
#include "Board.h"
#include "Game.h"


// Function -- Check if user wants to play a saved game or start a new one
void LoadPausedGameCheck(Board& BoardObject) {
	// Declare variable to store user's response to whether they want to load in a previous game or not
	char UserAnswer;

	// Ask if they want to load in a paused game
	cout << "\nWould you like to load in a paused game? \nPress 'Y' to say Yes OR 'N' for No : ";
	cin >> UserAnswer;

	// Convert the char to uppercase
	UserAnswer = toupper(UserAnswer);

	// Error-Handling: Make sure they only input either Y or N; nothing else
	while (UserAnswer != 89 && UserAnswer != 78)
	{
		// Ask if they want to load in a paused game
		cout << "\nWrong value, try again. \nPress 'Y' to say Yes OR 'N' for No : ";
		cin >> UserAnswer;

		// Convert the char to uppercase
		UserAnswer = toupper(UserAnswer);
	}

	// If yes load up the stored game board
	if (UserAnswer == 'Y')
	{
		BoardObject.LoadPausedBoard();
	}
	system("CLS");
}

// Function -- Check if user wants to start a game of Connect Four or not
char UserResponse() {
	// Declare variable to store user's response to whether they want to start playing a game or not
	char UserValue;

	// Ask them the question and store their response in the variable
	cout << "Ready to play a game of connect four? \nPress 'Y' to say start OR 'N' to exit the console : ";
	cin >> UserValue;

	// Convert the char to uppercase
	UserValue = toupper(UserValue);

	// Error Handling: Make sure they put in the correct values
	while (UserValue != 89 && UserValue != 78)
	{
		// Ask if they want to load in a paused game
		cout << "\nWrong value, try again. \nPress 'Y' to say start OR 'N' to exit the console : ";
		cin >> UserValue;

		// Convert the char to uppercase
		UserValue = toupper(UserValue);
	}

	// return the final response
	return UserValue;
}


// Main function that runs the entire game
int main()
{
	// Declare Variable to store the user's answer to whether they want to start a game or not
	char UserAnswer = UserResponse();

	// If the User wants to start a game
	while (UserAnswer == 'Y')
	{
		// Start a game - Define Objects 
		Game RunGame;
		Board GameBoard;
		Player Player1;
		Player Player2;

		// Check if user wants to load in a previous game's board or not
		LoadPausedGameCheck(GameBoard);

		// Call the Method - PlayerSymbol: Obtain and assign player symbols before starting the game
		Player1.SetPlayerSymbol(Player1, Player2);

		// Output: Inform the players of what their assigned symbols are
		system("CLS");
		cout << "Player 1: " << Player1.GetSymbol() << endl;
		cout << "Player 2: " << Player2.GetSymbol() << endl;
		system("PAUSE");
		system("CLS");

		// Call the Method - PrintBoard: Display the ASCII Art Board in Console Window
		GameBoard.PrintBoard(GameBoard.GetBoard());

		// Call the Method -- Decide who should play first
		RunGame.FirstPlayer(Player1, Player2, GameBoard.GetXCount(), GameBoard.GetOCount());

		// Game runs until someone is declared as a winner OR the game has not been paused
		while (RunGame.WinCondition(GameBoard.GetBoard()) == false)
		{
			RunGame.UpdatePlayerTurn(Player1.GetSymbol(), Player2.GetSymbol(), RunGame.GetPlayerTurn(), RunGame.WinCondition(GameBoard.GetBoard()));
			RunGame.CheckTurn(Player1, Player2, GameBoard.GetBoard());
			GameBoard.UpdateBoard(Player1, Player2, RunGame);
			GameBoard.SavePausedBoard(RunGame);
		}

		// Ask the user if they want to play again
		system("PAUSE");
		system("CLS");
		UserAnswer = UserResponse();
	}

	// Clear the screen and end the program
	system("CLS");
	cout << "See you later!" << endl;
}