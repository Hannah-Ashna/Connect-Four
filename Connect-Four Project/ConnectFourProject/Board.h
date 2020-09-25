// Include Guard
#if !defined (BOARD_H)
#define BOARD_H

// Declaration of Headers
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

// Include Game class
#include "Game.h"



class Board {
public:
	// Method -- Get Board Data
	vector<vector<string>> GetBoard() { return BoardLayout; }

	// Method -- Get XCount Value
	int GetXCount() { return XCount; }

	// Method -- Get OCount Value
	int GetOCount() { return OCount; }

	// Method -- Set the values of Board
	void SetBoard(vector<vector<string>> Board) { this->BoardLayout = BoardLayout; }

	// Method -- Cycle through the Board 2D Vector and display it
	void PrintBoard(const vector<vector<string>> BoardVector) {

		// Display the Column numbers for users
		cout << "\t\t| 1 | 2 | 3 | 4 | 5 | 6 |" << endl;
		cout << "\t\t-------------------------" << endl;

		// Loop through the board and print it out
		// Cycle through each Row First
		for (unsigned int RowLoop = 0; RowLoop < BoardVector.size(); RowLoop++)
		{
			// Use tabs to make the board stand out a little bit
			cout << "\t\t";
			// Cycle through each Column of that particular row
			for (unsigned int ColumnLoop = 0; ColumnLoop < BoardVector.size(); ColumnLoop++)
			{
				// Formatting done to make a distinction between each box on the grid
				cout << "| " << BoardVector[RowLoop][ColumnLoop] << " ";
			}

			// Formatting done to display the rows as being separate from each other
			cout << "|" << endl;
			cout << "\t\t-------------------------" << endl;

		}
	}

	// Method -- Update the board with the player's choice and display it
	void UpdateBoard(Player& PlayerObject1, Player& PlayerObject2, Game& GameObject) {

		// Make sure the board is only updated when the game has not been stopped/paused
		if (GameObject.GetGamePausedBool() == false)
		{
			if ((GameObject.GetPlayerTurn() == PlayerObject1.GetSymbol()) && (GameObject.GetPlayerTurn() != PlayerObject2.GetSymbol()))
			{
				// Update the LastColumn value to check win condition later
				GameObject.SetLastColumn(PlayerObject1.GetChoice());

				// Save the column choice to be used in the loop
				int ColumnChoice = PlayerObject1.GetChoice();

				// Pre-define the number of Rows we need to loop through
				int RowLoop = BoardLayout.size() - 1;

				// Loop through the board
				// Cycle through each Row for that particular column choice
				for (RowLoop; RowLoop >= 0; RowLoop--)
				{
					// Check if there is an empty slot
					if (BoardLayout[RowLoop][ColumnChoice] == " ")
					{
						// Update the board with the player's symbol
						BoardLayout[RowLoop][ColumnChoice] = PlayerObject1.GetSymbol();

						// Update the LastRow value to check win condition later
						GameObject.SetLastRow(RowLoop);

						// Break out of this loop
						break;
					}
				}
			}

			else {

				// Update the LastColumn value to check win condition later
				GameObject.SetLastColumn(PlayerObject2.GetChoice());

				// Save the column choice to be used in the loop
				int ColumnChoice = PlayerObject2.GetChoice();

				// Pre-define the number of Rows we need to loop through
				int RowLoop = BoardLayout.size() - 1;

				// Loop through the board
				// Cycle through each Row for that particular column choice
				for (RowLoop; RowLoop >= 0; RowLoop--)
				{
					// Check if there is an empty slot
					if (BoardLayout[RowLoop][ColumnChoice] == " ")
					{
						// Update the board with the player's symbol
						BoardLayout[RowLoop][ColumnChoice] = PlayerObject2.GetSymbol();

						// Update the LastRow value to check win condition later
						GameObject.SetLastRow(RowLoop);

						// Break out of this loop
						break;
					}
				}
			}
		}
		// Clear the screen before printing the board
		system("CLS");
		PrintBoard(GetBoard());
	}

	// Method -- Checks whether user has chosen to save the game, if yes it saves the board
	void SavePausedBoard(Game& GameObject) {

		if (GameObject.GetGamePausedBool() == true)
		{
			// Create and open a text file
			ofstream SaveBoard("PausedGameBoard.txt");

			// Loop through the board 
			// Cycle through each Row First
			for (unsigned int RowLoop = 0; RowLoop < GetBoard().size(); RowLoop++)
			{
				// Cycle through each Column of that particular row
				for (unsigned int ColumnLoop = 0; ColumnLoop < GetBoard().size(); ColumnLoop++)
				{
					// Formatting done to save each symbol on a new line
					SaveBoard << GetBoard()[RowLoop][ColumnLoop] << "\n";
				}

			}

			// Close the file once finished
			SaveBoard.close();
		}

	}

	// Method -- Load in a previously saved board from a paused game
	void LoadPausedBoard() {

		// Read the data from the file
		ifstream ReadSavedBoard("PausedGameBoard.txt");

		// Store each line's data in a temporary string
		string BoardData;

		// Cycle through each Row First
		for (unsigned int RowLoop = 0; RowLoop < GetBoard().size(); RowLoop++)
		{
			// Cycle through each Column of that particular row
			for (unsigned int ColumnLoop = 0; ColumnLoop < GetBoard().size(); ColumnLoop++)
			{
				// Obtain the data from each line then store it in the board vector
				getline(ReadSavedBoard, BoardData);
				BoardLayout[RowLoop][ColumnLoop] = BoardData;
				
				// Check which symbol it is - If X increment XCount variable
				if (BoardData == "X")
				{
					XCount++;
				}

				// Check which symbol it is - If O increment OCount variable
				else if (BoardData == "O") 
				{
					OCount++;
				}
			}

		}

		ReadSavedBoard.close();
	}


private:
	// Define the Game Board's Layout
	vector<vector<string>> BoardLayout = { {" "," "," "," "," "," "}, {" "," "," "," "," "," "}, {" "," "," "," "," "," "},
									{" "," "," "," "," "," "}, {" "," "," "," "," "," "}, {" "," "," "," "," "," "} };

	// Variables to count how many of each symbol is present
	int XCount = 0;
	int OCount = 0;
};

#endif
