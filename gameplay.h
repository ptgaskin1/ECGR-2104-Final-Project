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
		vector<int> playerMeld1;
		vector<int> playerMeld2;
		vector<int> playerMeld3;
		vector<int> computerHand;
		vector<int> computerMeld1;
		vector<int> computerMeld2;
		vector<int> computerMeld3;
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
	
	cout << endl << "Player Hand: ";
	for(int i=0; i<playerHand.size(); i++){
		cout << deck[playerHand[i]%13][playerHand[i]%4] << "<-" << i;
	}
	cout << endl << endl;
	if(playerMeld1.size()>0){
		cout << endl << "Player Melds: ";
		for(int i=0; i<playerMeld1.size(); i++){
			cout << deck[playerMeld1[i]%13][playerMeld1[i]%4] << "<-" << i;
		}
		for(int i=0; i<playerMeld2.size(); i++){
			cout << deck[playerMeld2[i]%13][playerMeld2[i]%4] << "<-" << i;
		}
		for(int i=0; i<playerMeld3.size(); i++){
			cout << deck[playerMeld3[i]%13][playerMeld3[i]%4] << "<-" << i;
		}
		cout << endl << endl;
	}
	cout << endl << "Computer Hand: ";
	for(int i=0; i<computerHand.size(); i++){
		cout << deck[computerHand[i]%13][computerHand[i]%4] << "<-" << i;
	}
	cout << endl << endl;
	if(computerMeld1.size()>0){
		cout << endl << "Computer Melds: ";
		for(int i=0; i<computerMeld1.size(); i++){
			cout << deck[computerMeld1[i]%13][computerMeld1[i]%4] << "<-" << i;
		}
		for(int i=0; i<computerMeld2.size(); i++){
			cout << deck[computerMeld2[i]%13][computerMeld2[i]%4] << "<-" << i;
		}
		for(int i=0; i<computerMeld3.size(); i++){
			cout << deck[computerMeld3[i]%13][computerMeld3[i]%4] << "<-" << i;
		}
		cout << endl << endl;
	}
	cout << endl << "Discard Pile: ";
	for(int i=0; i<discardPile.size(); i++){
		cout << deck[discardPile[i]%13][discardPile[i]%4];
	}
	cout << endl << endl;
	cout << endl << "Stock Pile: ";
	for(int i=0; i<stockPile.size(); i++){
		cout << deck[stockPile[i]%13][stockPile[i]%4];
	}
	cout << endl << endl;

}

void gameplay::findMelds() {

//find and optimize the melds (sets and runs) in player/computer's hand

}

void gameplay::drawCard() {
	turn++;
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
		discardPile.push_back(computerHand[cardChoice-1]);
		computerHand.erase(computerHand.begin()+cardChoice);
	}

}

void gameplay::knock() { //IDENTICAL TO discardCard
	int cardChoice = 0;
	cout << endl << "Enter a number between 0-9 to select a card from your hand to discard (10 was just drawn so it cannot be discarded this turn): ";
	cin >> cardChoice;
	if(turn%2==1){		
		discardPile.push_back(playerHand[cardChoice]);
		playerHand.erase(playerHand.begin()+cardChoice);
	}	
	else if(turn%2==0){
		discardPile.push_back(computerHand[cardChoice-1]);
		computerHand.erase(computerHand.begin()+cardChoice);
	}
}

int gameplay::scorePlayerDeadwood() {
	int sum = 0;	
	for(int i = 0; i < playerHand.size(); i++) {
		if(playerHand[i]%13 < 10) {
			sum += playerHand[i]%13+1;
		}
		else {
			sum += 10;
		}
	}
	for(int i = 0; i < playerMeld1.size(); i++) {
		if(playerMeld1[i]%13 < 10) {
			sum -= playerMeld1[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < playerMeld2.size(); i++) {
		if(playerMeld2[i]%13 < 10) {
			sum -= playerMeld2[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < playerMeld3.size(); i++) {
		if(playerMeld3[i]%13 < 10) {
			sum -= playerMeld3[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	return sum;
}

int gameplay::scoreCPUDeadwood() {
	int sum = 0;	
	for(int i = 0; i < computerHand.size(); i++) {
		if(computerHand[i]%13 < 10) {
			sum += computerHand[i]%13+1;
		}
		else {
			sum += 10;
		}
	}
	for(int i = 0; i < computerMeld1.size(); i++) {
		if(computerMeld1[i]%13 < 10) {
			sum -= computerMeld1[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < computerMeld2.size(); i++) {
		if(computerMeld2[i]%13 < 10) {
			sum -= computerMeld2[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	for(int i = 0; i < computerMeld3.size(); i++) {
		if(computerMeld3[i]%13 < 10) {
			sum -= computerMeld3[i]%13+1;
		}
		else {
			sum -= 10;
		}
	}
	return sum;
}

#endif
