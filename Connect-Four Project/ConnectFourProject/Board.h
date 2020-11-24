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
	void PrintBoard(const vector<vector<string>> BoardVector);

	// Method -- Update the board with the player's choice and display it
	void UpdateBoard(Player& PlayerObject1, Player& PlayerObject2, Game& GameObject);

	// Method -- Checks whether user has chosen to save the game, if yes it saves the board
	void SavePausedBoard(Game& GameObject);

	// Method -- Load in a previously saved board from a paused game
	void LoadPausedBoard();


private:
	// Define the Game Board's Layout
	vector<vector<string>> BoardLayout = { {" "," "," "," "," "," "}, {" "," "," "," "," "," "}, {" "," "," "," "," "," "},
									{" "," "," "," "," "," "}, {" "," "," "," "," "," "}, {" "," "," "," "," "," "} };

	// Variables to count how many of each symbol is present
	int XCount = 0;
	int OCount = 0;
};

#endif
