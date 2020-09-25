// Include Guard
#if !defined (GAME_H)
#define GAME_H

// Declaration of Headers
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

// Include Player Class
#include "Player.h"


class Game {
public:

	// Method -- Get Current Player Turn Data
	string GetPlayerTurn() { return PlayerTurn; }

	// Method -- Set Current Player Turn
	void SetPlayerTurn(string PlayerTurn) { this->PlayerTurn = PlayerTurn; }

	// Method -- Assign Player turns and successfully alternate it
	void UpdatePlayerTurn(string Player1Symbol, string Player2Symbol, string CurrentPlayerTurn, bool WinStatus) {

		// Private Variable for this Function to just store which player is up next for the output
		string PlayerNumber = "";

		if (WinStatus == false) {

			// If - Switch from Player 1 to Player 2;
			if (CurrentPlayerTurn == Player1Symbol)
			{
				CurrentPlayerTurn = Player2Symbol;
				PlayerNumber = "Player 2";
			}

			// Else - Switch from Player 2 to Player 1;
			else
			{
				CurrentPlayerTurn = Player1Symbol;
				PlayerNumber = "Player 1";
			}

			// Inform players of whose turn it is after it has been updated
			cout << "\n" << PlayerNumber << " - " << CurrentPlayerTurn << " it is now your turn" << endl;
			SetPlayerTurn(CurrentPlayerTurn);
		}

		else
		{
			cout << "We have a winner! - GAME OVER" << endl;
		}

	}

	// Method  -- Get User's input by taking into account the player object
	void UserInput(Player& PlayerObject, vector<vector<string>> GameBoard) {

		// Declare Variables with a random value
		int ColumnChoice = 10;
		int TempValue = 5;

		cout << "\nPlayer please put in your row choice (1 - 6) or 7 if you want to pause the game: ";
		cin >> ColumnChoice;

		// Subtract by 1 to fit the indexing values of 0 - 5 for the vector
		ColumnChoice--;

		if (ColumnChoice >= 0 && ColumnChoice <= 5)
		{
			// Store the columnvalue temporarily here for special error check -- prevent full columns from being used
			TempValue = ColumnChoice;
			cout << TempValue;
		}
		
		// Use while loop to prevent errors with user's column choice
		while (cin.fail() || (ColumnChoice < 0 || ColumnChoice > 6) || GameBoard[0][TempValue] != " ")
		{
			// Clear the input buffer so that cin can be restored to a usable state
			cin.clear();
			// Ignore the last input value
			cin.ignore(INT_MAX, '\n');
			cout << "The value you've chosen is unacceptable, try again!" << endl;

			cout << "\nPlayer please put in your row choice (1 - 6) or 7 if you want to pause the game: ";
			cin >> ColumnChoice;

			// Subtract by 1 to fit the indexing values of 0 - 5 for the vector
			ColumnChoice--;

			if (ColumnChoice >= 0 && ColumnChoice <= 5)
			{
				// Store the columnvalue temporarily here for special error check -- prevent full columns from being used
				TempValue = ColumnChoice;
				cout << TempValue;
			}
		}

		// Update row choice
		if (ColumnChoice >= 0 && ColumnChoice <= 5)
		{
			PlayerObject.UpdatePlayerChoice(ColumnChoice);
		}

		// Option to pause the game 
		else if (ColumnChoice == 6)
		{
			GamePaused = true;
		}

		cout << "Player Choice Successful - " << PlayerObject.GetChoice();
	}

	// Method -- Check whose turn it is and then ask for input
	void CheckTurn(Player& PlayerObject1, Player& PlayerObject2, vector<vector<string>> GameBoard) {

		if ((GetPlayerTurn() == PlayerObject1.GetSymbol()) && (GetPlayerTurn() != PlayerObject2.GetSymbol()))
		{
			UserInput(PlayerObject1, GameBoard);
		}

		else
		{
			UserInput(PlayerObject2, GameBoard);
		}
	}

	// Method -- Decide who starts the game first
	void FirstPlayer(Player& PlayerObject1, Player& PlayerObject2, int XCount, int OCount) {

		// Decided who should start the game first
		// When there are more X symbols that O symbols, the player with the O symbol should start first
		if (XCount > OCount)
		{
			if (PlayerObject1.GetSymbol() == "O")
			{
				SetPlayerTurn(PlayerObject2.GetSymbol());
			}

			else
			{
				SetPlayerTurn(PlayerObject1.GetSymbol());
			}
		}

		// When there are more O symbols that X symbols, the player with the X symbol should start first
		else if (OCount > XCount)
		{
			if (PlayerObject1.GetSymbol() == "X")
			{
				SetPlayerTurn(PlayerObject2.GetSymbol());
			}

			else
			{
				SetPlayerTurn(PlayerObject1.GetSymbol());
			}
		}

		// When neither of those scenarios are true, let player 1 start first
		else
		{
			SetPlayerTurn(PlayerObject2.GetSymbol());
		}
	}

	// Method -- Set value for LastColumn
	void SetLastColumn(int LastColumn) { this->LastColumn = LastColumn; }

	// Method -- Get value for LastColumn
	int GetLastColumn() { return LastColumn; }

	// Method -- Set value for LastRow
	void SetLastRow(int LastRow) { this->LastRow = LastRow; }

	// Method -- Get value for LastRow
	int GetLastRow() { return LastRow; }

	// Method -- Check if anyone has won the game yet
	bool WinCondition(vector<vector<string>> GameBoard) {

		// Declare SuccessCounter Variable - Used to check whether a player gets 4 in a row (Only for Horizontal and Vertical)
		int SuccessCounter = 0;

		// Boolean variable to stop game if WinnerDeclared = true
		bool WinnerDeclared = false;

		// Alternative Win: Game has been paused
		if (GamePaused == true)
		{
			cout << "\nGame Paused and saved for later!" << endl;
			WinnerDeclared = true;
		}

		// Win - Horizontal
		for (int i = 0; i < 6; i++)
		{

			if (GameBoard[GetLastRow()][i] == GetPlayerTurn())
			{
				SuccessCounter++;
			}

			else
			{
				SuccessCounter = 0;
			}

			if (SuccessCounter >= 4)
			{
				cout << "\nWe've got ourselves a winner - Horizontal!" << endl;
				cout << "Player " << PlayerTurn << " - is the winner" << endl;
				WinnerDeclared = true;
			}
		}

		// Win - Vertical
		for (int i = 0; i < 6; i++)
		{
			if (GameBoard[i][GetLastColumn()] == GetPlayerTurn())
			{
				SuccessCounter++;
			}

			else
			{
				SuccessCounter = 0;
			}

			if (SuccessCounter >= 4)
			{
				cout << "\nWe've got ourselves a winner - Vertical!" << endl;
				cout << "Player " << PlayerTurn << " - is the winner" << endl;
				WinnerDeclared = true;

			}
		}

		// Win - Diagonals Ascending: Link in declaration
		for (unsigned int i = 3; i < 6; i++)
		{
			for (unsigned int j = 0; j < 6 - 3; j++)
			{
				if (GameBoard[i][j] == GetPlayerTurn() && GameBoard[i - 1][j + 1] == GetPlayerTurn() && GameBoard[i - 2][j + 2] == GetPlayerTurn() && GameBoard[i - 3][j + 3] == GetPlayerTurn())
				{
					cout << "\nWe've got ourselves a winner - Diagonal" << endl;
					cout << "Player " << PlayerTurn << " - is the winner" << endl;
					WinnerDeclared = true;
				}
			}
		}

		// Win - Diagonals Descending: Link in declaration
		for (unsigned int i = 3; i < 6; i++)
		{
			for (unsigned int j = 3; j < 6; j++)
			{
				if (GameBoard[i][j] == GetPlayerTurn() && GameBoard[i - 1][j - 1] == GetPlayerTurn() && GameBoard[i - 2][j - 2] == GetPlayerTurn() && GameBoard[i - 3][j - 3] == GetPlayerTurn())
				{
					cout << "\nWe've got ourselves a winner - Diagonal" << endl;
					cout << "Player " << PlayerTurn << " - is the winner" << endl;
					return true;
				}
			}
		}

		return WinnerDeclared;

	}

	// Method -- Get value for GamePaused
	bool GetGamePausedBool() { return GamePaused; }

private:

	// Stored the symbol of the current player
	string PlayerTurn = " ";

	// Contains the Column number that was last used
	int LastColumn = NULL;

	// Contains the Row number that was last used
	int LastRow = NULL;

	// Whether the game has been paused or not
	bool GamePaused = false;
};

#endif