#include "gameplay.h"

using namespace std;

int main() {
	gameplay game;

	string keepPlaying = "";

	while(keepPlaying != "n" && keepPlaying != "N"){

		game.drawCard();
		cout << "Enter 'n' or 'N' to knock and end the game, or enter any other key to continue: ";
		cin >> keepPlaying;
		if(keepPlaying == "n" || keepPlaying == "N") {
			game.knock();
		}
		else{
			game.discardCard();
		}

	}
	
	
	cout << "Player deadwood: " << game.scorePlayerDeadwood() << endl;
	cout << "CPU deadwood: " << game.scoreCPUDeadwood() << endl;
	if (game.scorePlayerDeadwood() < game.scoreCPUDeadwood()) {
		cout << "The player wins the round!\n";
	}
	else if (game.scorePlayerDeadwood() > game.scoreCPUDeadwood()) {
		cout << "The cpu wins the round!\n";
	}
	else {
		cout << "The round ends in a tie!\n";
	}
}


















