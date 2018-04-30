#include "gameplay.h"

using namespace std;

int main() {
	gameplay game;

	bool keepPlaying = 1;

	while(keepPlaying == 1){

		game.findMelds();
		game.displayAllCards();
		game.drawCard();
		game.findMelds();
		game.displayAllCards();
		cout << "Enter 1 to discard or 0 to knock (end game): ";
		cin >> keepPlaying;
		if(keepPlaying == 1) {
			game.discardCard();
		}
		else if(keepPlaying == 0) {
			game.knock();
		}

	}
	
	game.findMelds();
	game.displayAllCards();
	
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


















