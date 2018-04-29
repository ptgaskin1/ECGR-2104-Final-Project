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
		int getPlayerDeadwood();
		int getCPUDeadwood();
		void discardCard();
		void knock();
		void takeTurn();
	private:
		vector<int> stockPile;
		vector<int> discardPile;
		vector<int> playerHand;
		vector<int> computerHand;
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
		cout << deck[playerHand[i]%13][playerHand[i]%4];
	}
	cout << endl << endl;
	cout << endl << "Computer Hand: ";
	for(int i=0; i<computerHand.size(); i++){
		cout << deck[computerHand[i]%13][computerHand[i]%4];
	}
	cout << endl << endl;
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


void gameplay::discardCard() {

	int cardChoice = 1;
	cout << "Discard a card from your hand. Enter an integer 1-11 to select your card: ";
	cin >> cardChoice;
	if(turn%2==1){		
		discardPile.push_back(playerHand[cardChoice-1]);
		playerHand.erase(playerHand.begin()+(cardChoice-1));
	}	
	else if(turn%2==0){
		discardPile.push_back(computerHand[cardChoice-1]);
		computerHand.erase(computerHand.begin()+(cardChoice-1));
	}	

}

int gameplay::getPlayerDeadwood() {
	int x;
	int sum = 0;	
	for(int i = 0; i < 10; i++) {
		if(playerHand[i]%13 < 10) {
			x = playerHand[i]%13+1;
		}
		else {
			x = 10;
		}
		sum += x;
	}
	return sum;
}

int gameplay::getCPUDeadwood() {
	int x;
	int sum = 0;	
	for(int i = 0; i < 10; i++) {
		if(computerHand[i]%13 < 10) {
			x = computerHand[i]%13+1;
		}
		else {
			x = 10;
		}
		sum += x;
	}
	return sum;
}

void gameplay::knock() {
	int cardChoice = 1;
	cout << "Discard a card from your hand. Enter an integer 1-11 to select your card: ";
	cin >> cardChoice;
	if(turn%2==1){		
		discardPile.push_back(playerHand[cardChoice-1]);
		playerHand.erase(playerHand.begin()+(cardChoice-1));
	}	
	else if(turn%2==0){
		discardPile.push_back(computerHand[cardChoice-1]);
		computerHand.erase(computerHand.begin()+(cardChoice-1));
	}
}

void gameplay::takeTurn() {
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

#endif
