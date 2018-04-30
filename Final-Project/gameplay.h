#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "card.h"
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
		//void findMelds();
		void drawCard();
		void discardCard();
		void knock();
		int scorePlayerDeadwood();
		int scoreCPUDeadwood();
	private:
		vector<card> stockPile;
		vector<card> discardPile;
		vector<card> playerHand;
		//vector< vector<int> > playerMelds;
		vector<card> computerHand;
		//vector< vector<int> > computerMelds;
		int turn;
};

gameplay::gameplay() {
	turn = 0;
	
	for(int i=0; i<13; i++){
		for(int j=0; j<4; j++){
			card card1(i,j);
			stockPile.push_back(card1);
		}
	}
	
	for(int i=0; i < stockPile.size(); i++){
		int j = (rand() + time(0))% 52;
		card temp = stockPile[i];
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

	cout << endl << "Your Hand: ";
	for(int i=0; i<playerHand.size(); i++){
		playerHand[i].printCard();
		cout << "<-" << i;
	}
	
	cout << endl << endl;
	
	cout << endl << "Computer Hand: ";
	for(int i=0; i<computerHand.size(); i++){
		computerHand[i].printCard();
		cout <<  "<-" << i;
	}

	cout << endl << endl;

	cout << endl << "Discard Pile: ";
	for(int i=0; i<discardPile.size(); i++){
		discardPile[i].printCard();
	}

	cout << endl << endl;
	
	cout << endl << "Stock Pile: ";
	for(int i=0; i<stockPile.size(); i++){
		stockPile[i].printCard();
	}

	cout << endl << endl;
}

void gameplay::findMelds() {
	//find the melds in the player/computer's hand
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
		sum += playerHand[i].getValue();
	}
	return sum;
}

int gameplay::scoreCPUDeadwood() {
	int sum = 0;	
	for(int i = 0; i < computerHand.size(); i++) {
		sum += computerHand[i].getValue();
	}
	return sum;
}

#endif








