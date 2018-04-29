#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "gameplay.h"

using namespace std;

int main() {
	gameplay game;

	int h;
	bool x = 0;

	while(x != 1){

		game.displayAllCards();
		game.takeTurn();
		game.displayAllCards();
		cout << "Enter 1 to discard or 2 to knock: ";
		cin >> h;
		if(h == 1) {
			game.discardCard();
		}
		else if(h == 2) {
			game.knock();
			x = 1;
		}

	}
	
	game.displayAllCards();
	
	cout << "Player deadwood: " << game.getPlayerDeadwood() << endl;
	cout << "CPU deadwood: " << game.getCPUDeadwood() << endl;
	if (game.getPlayerDeadwood() < game.getCPUDeadwood()) {
		cout << "The player wins the round!\n";
	}
	else if (game.getPlayerDeadwood() > game.getCPUDeadwood()) {
		cout << "The cpu wins the round!\n";
	}
	else {
		cout << "The round ends in a tie!\n";
	}
}


















