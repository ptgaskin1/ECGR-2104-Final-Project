#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


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


	vector<int> playerHand;
	vector<int> computerHand;
	vector<int> discardPile;
	vector<int> stockPile;
	int turn=0;

void setupGame(){

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

void displayAllCards(){

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

void takeTurn(){

	turn++;
	int drawSelect=0;
	while(drawSelect!=1 && drawSelect!=2){
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
			stockPile.pop_back();
		}
		else if(drawSelect==2 && turn%2==0){
			computerHand.push_back(discardPile.back());
			stockPile.pop_back();
		}
	}

}

int main(){
	
	setupGame();

	while(true){

		displayAllCards();
		takeTurn();

	}

}
