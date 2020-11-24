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
	void UpdatePlayerTurn(string Player1Symbol, string Player2Symbol, string CurrentPlayerTurn, bool WinStatus);

	// Method  -- Get User's input by taking into account the player object
	void UserInput(Player& PlayerObject, vector<vector<string>> GameBoard);

	// Method -- Check whose turn it is and then ask for input
	void CheckTurn(Player& PlayerObject1, Player& PlayerObject2, vector<vector<string>> GameBoard);

	// Method -- Decide who starts the game first
	void FirstPlayer(Player& PlayerObject1, Player& PlayerObject2, int XCount, int OCount);

	// Method -- Set value for LastColumn
	void SetLastColumn(int LastColumn) { this->LastColumn = LastColumn; }

	// Method -- Get value for LastColumn
	int GetLastColumn() { return LastColumn; }

	// Method -- Set value for LastRow
	void SetLastRow(int LastRow) { this->LastRow = LastRow; }

	// Method -- Get value for LastRow
	int GetLastRow() { return LastRow; }

	// Method -- Check if anyone has won the game yet
	bool WinCondition(vector<vector<string>> GameBoard);

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