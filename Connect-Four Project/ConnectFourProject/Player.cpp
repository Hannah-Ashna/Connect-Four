#include "Player.h"


// Method -- Assign user to either X or O
void Player::SetPlayerSymbol(Player& PlayerObject1, Player& PlayerObject2) {

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
