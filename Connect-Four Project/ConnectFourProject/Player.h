// Include Guard
#if !defined (PLAYER_H)
#define PLAYER_H

// Declaration of Headers
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


class Player {
public:
	// Method -- Get Player Symbol
	string GetSymbol() { return ChosenSymbol; }

	// Method -- Update the Player's Chosen Symbol
	void UpdateChosenSymbol(string ChosenSymbol) { this->ChosenSymbol = ChosenSymbol; }

	// Method -- Get Player Choice
	int GetChoice() { return PlayerChoice; }

	// Method -- Update the Player's Choice
	void UpdatePlayerChoice(int PlayerChoice) { this->PlayerChoice = PlayerChoice; }

	// Method -- Assign user to either X or O
	void SetPlayerSymbol(Player& PlayerObject1, Player& PlayerObject2);


private:
	string ChosenSymbol = "";
	int PlayerChoice = 0;
};

#endif