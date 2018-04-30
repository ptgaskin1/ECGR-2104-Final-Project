#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class gameplay {
	public:
		gameplay();		
		void displayAllCards();
		//void checkRun();
		//void checkStack();
		//void defendKnock();
		void findMelds();
		void drawCard();
		void discardCard();
		void knock();
		int scorePlayerDeadwood();
		int scoreCPUDeadwood();
	private:
		vector<int> stockPile;
		vector<int> discardPile;
		vector<int> playerHand;
		vector< vector<int> > playerMelds;
		vector<int> computerHand;
		vector< vector<int> > computerMelds;
		int turn;
};

/*class cpuPlayer : public gameplay {
	public:
		void chooseDrawPile();
		void chooseDiscard();
		void chooseKnock();
	private:
		
};*/

gameplay::gameplay() {
	
	turn = 0;

	for(int i=0; i<52; i++){
		stockPile.push_back(i);
	}

	for(int i=0; i<52; i++){
		int j = (rand() + time(0))% 52;
		int temp = stockPile[i];
		stockPile[i]=stockPile[j];
		stockPile[j]=temp;
	}

	for(int i=0; i<10; i++){
		playerHand.push_back(stockPile[0]);
		stockPile.erase(stockPile.begin());
	}

	for(int i=0; i<10; i++){
		computerHand.push_back(stockPile[0]);
		stockPile.erase(stockPile.begin());
	}
	
	discardPile.push_back(stockPile[0]);
	stockPile.erase(stockPile.begin());
}

void gameplay::displayAllCards() {

	findMelds();

	string deck[13][4] = {
		
		{ " 🂡 " , " 🂱 " , " 🃁 " , " 🃑 " },

		{ " 🂢 " , " 🂲 " , " 🃂 " , " 🃒 " },

		{ " 🂣 " , " 🂳 " , " 🃃 " , " 🃓 " },

		{ " 🂤 " , " 🂴 " , " 🃄 " , " 🃔 " },

		{ " 🂥 " , " 🂵 " , " 🃅 " , " 🃕 " },

		{ " 🂦 " , " 🂶 " , " 🃆 " , " 🃖 " },

		{ " 🂧 " , " 🂷 " , " 🃇 " , " 🃗 " },

		{ " 🂨 " , " 🂸 " , " 🃈 " , " 🃘 " },

		{ " 🂩 " , " 🂹 " , " 🃉 " , " 🃙 " },

		{ " 🂪 " , " 🂺 " , " 🃊 " , " 🃚 " },

		{ " 🂫 " , " 🂻 " , " 🃋 " , " 🃛 " },

		{ " 🂭 " , " 🂽 " , " 🃍 " , " 🃝 " },

		{ " 🂮 " , " 🂾 " , " 🃎 " , " 🃞 " }

	};
	
	cout << endl << "Your Hand: ";
	for(int i=0; i<playerHand.size(); i++){
		cout << deck[playerHand[i]/4][playerHand[i]%4] << "<-" << i;
	}
	cout << endl << endl;
	if(playerMelds.size()>0){
		cout << endl << "Possible Melds: ";
		for(int i=0; i<playerMelds.size(); i++){
			cout << " , ";
			for(int j=0; j<playerMelds[i].size(); j++){
				cout << deck[playerMelds[i][j]/4][playerMelds[i][j]%4];
			}
		}
		cout << endl << endl;
	}
	cout << endl << "Computer Hand: ";
	for(int i=0; i<computerHand.size(); i++){
		cout << deck[computerHand[i]/4][computerHand[i]%4] << "<-" << i;
	}
	cout << endl << endl;
	if(computerMelds.size()>0){
		cout << endl << "Computer Melds: ";
		for(int i=0; i<computerMelds.size(); i++){
			for(int j=0; j<computerMelds[i].size(); j++){
				cout << deck[computerMelds[i][j]/4][computerMelds[i][j]%4];
			}
		}
		cout << endl << endl;
	}
	cout << endl << "Discard Pile: ";
	for(int i=0; i<discardPile.size(); i++){
		cout << deck[discardPile[i]/4][discardPile[i]%4];
	}
	cout << endl << endl;
	cout << endl << "Stock Pile: ";
	for(int i=0; i<stockPile.size(); i++){
		cout << deck[stockPile[i]/4][stockPile[i]%4];
	}
	cout << endl << endl;

}

void gameplay::findMelds() {
//find and optimize the melds (sets and runs) in player/computer's hand
	int playerMeldsCount=0;
	playerMelds.resize(0);
	for(int i=0; i<playerHand.size(); i++){	
		for(int j=i+1; j<playerHand.size(); j++){
			if(playerHand[j]/4==playerHand[i]/4){
				for(int k=j+1; k<playerHand.size(); k++){
					if(playerHand[k]/4==playerHand[j]/4){
						playerMelds.resize(playerMeldsCount+1);
						playerMelds[playerMeldsCount].push_back(playerHand[i]);
						playerMelds[playerMeldsCount].push_back(playerHand[j]);
						playerMelds[playerMeldsCount].push_back(playerHand[k]);
						for(int l=k+1; l<playerHand.size(); l++){
							if(playerHand[l]/4==playerHand[k]/4){
								playerMelds[playerMeldsCount].push_back(playerHand[l]);
							}
						}
						playerMeldsCount++;
					}
				}
			}
		}
	}
	for(int i=0; i<playerHand.size(); i++){	
		for(int j=i+1; j<playerHand.size(); j++){
			if(playerHand[j]%4==playerHand[i]%4){
				for(int k=j+1; k<playerHand.size(); k++){
					if(playerHand[k]%4==playerHand[j]%4){
						//playerHand[i], playerHand[j], and playerHand[k] compare
						for(int l=k+1; l<playerHand.size(); l++){
							if(playerHand[l]%4==playerHand[k]%4){
								//playerHand[i], playerHand[j], playerHand[k], and playerHand[l] compare
								for(int m=l+1; m<playerHand.size(); m++){
									if(playerHand[m]%4==playerHand[l]%4){
									//playerHand[i], playerHand[j], playerHand[k], playerHand[l], and playerHand[m] compare (no more for loops needed since a run of six or more can be broken up into runs of three and four)
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int computerMeldsCount=0;
	computerMelds.resize(0);
	for(int i=0; i<computerHand.size(); i++){
		for(int j=i+1; j<computerHand.size(); j++){
			if(computerHand[j]/4==computerHand[i]/4){
				for(int k=j+1; k<computerHand.size(); k++){
					if(computerHand[k]/4==computerHand[j]/4){
						computerMelds.resize(computerMeldsCount+1);
						computerMelds[computerMeldsCount].push_back(computerHand[i]);
						computerMelds[computerMeldsCount].push_back(computerHand[j]);
						computerMelds[computerMeldsCount].push_back(computerHand[k]);
						for(int l=k+1; l<computerHand.size(); l++){
							if(computerHand[l]/4==computerHand[k]/4){
								computerMelds[computerMeldsCount].push_back(computerHand[l]);
							}
						}
						computerMeldsCount++;
					}
				}
			}
		}
	}
}

void gameplay::drawCard() {
	turn++;
	cout << "Turn #" << turn << endl;
	displayAllCards();
	int drawSelect=0;
	cout << "Draw a card. Enter 1 for Stock Pile or 2 for Discard Pile: ";
	cin >> drawSelect;
	if(drawSelect==1 && turn%2==1){
		playerHand.push_back(stockPile.back());
		stockPile.pop_back();
	}
	else if(drawSelect==1 && turn%2==0){
		computerHand.push_back(stockPile.back());
		stockPile.pop_back();
	}
	else if(drawSelect==2 && turn%2==1){
		playerHand.push_back(discardPile.back());
		discardPile.pop_back();
	}
	else if(drawSelect==2 && turn%2==0){
		computerHand.push_back(discardPile.back());
		discardPile.pop_back();
	}
	displayAllCards();
}


void gameplay::discardCard() {
	int cardChoice = 0;
	cout << endl << "Enter a number between 0-9 to select a card from your hand to discard (10 was just drawn so it cannot be discarded this turn): ";
	cin >> cardChoice;
	if(turn%2==1){		
		discardPile.push_back(playerHand[cardChoice]);
		playerHand.erase(playerHand.begin()+cardChoice);
	}	
	else if(turn%2==0){
		discardPile.push_back(computerHand[cardChoice]);
		computerHand.erase(computerHand.begin()+cardChoice);
	}

}

void gameplay::knock() {
	discardCard();
	displayAllCards();
}

int gameplay::scorePlayerDeadwood() {
	int sum = 0;	
	for(int i = 0; i < playerHand.size(); i++) {
		if(playerHand[i]/4 < 10) {
			sum += playerHand[i]/4+1;
		}
		else {
			sum += 10;
		}
	}
	/*for(int i = 0; i < playerMeld1.size(); i++) {
		if(playerMeld1[i]/4 < 10) {
			sum -= playerMeld1[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < playerMeld2.size(); i++) {
		if(playerMeld2[i]/4 < 10) {
			sum -= playerMeld2[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < playerMeld3.size(); i++) {
		if(playerMeld3[i]/4 < 10) {
			sum -= playerMeld3[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}*/
	return sum;
}

int gameplay::scoreCPUDeadwood() {
	int sum = 0;	
	for(int i = 0; i < computerHand.size(); i++) {
		if(computerHand[i]/4 < 10) {
			sum += computerHand[i]/4+1;
		}
		else {
			sum += 10;
		}
	}
	/*for(int i = 0; i < computerMeld1.size(); i++) {
		if(computerMeld1[i]/4 < 10) {
			sum -= computerMeld1[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < computerMeld2.size(); i++) {
		if(computerMeld2[i]/4 < 10) {
			sum -= computerMeld2[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < computerMeld3.size(); i++) {
		if(computerMeld3[i]/4 < 10) {
			sum -= computerMeld3[i]/4+1;
		}
		else {
			sum -= 10;
		}
	}*/
	return sum;
}

#endif
