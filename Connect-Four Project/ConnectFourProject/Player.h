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
	void SetPlayerSymbol(Player& PlayerObject1, Player& PlayerObject2) {

		// Store the user's choice in this temporary variable to carry out error handling
		char Temp;

		// Get user's input
		cout << "Player 1 gets first choice! Pick your Symbol (X or O): ";
		cin >> Temp;

		// Convert to Uppercase
		Temp = toupper(Temp);

		// Make sure that user only chooses X or O and nothing else
		while (Temp != 79 && Temp != 88)
		{
			// Get user's input
			cout << "\nWrong value, try again. Pick your Symbol (X or O): ";
			cin >> Temp;

			// Convert to Uppercase
			Temp = toupper(Temp);
		}

		if (Temp == 'O')
		{
			PlayerObject1.UpdateChosenSymbol("O");
			PlayerObject2.UpdateChosenSymbol("X");
		}

		else
		{
			PlayerObject1.UpdateChosenSymbol("X");
			PlayerObject2.UpdateChosenSymbol("O");
		}
				


	}


private:
	string ChosenSymbol = "";
	int PlayerChoice = 0;
};

#endif