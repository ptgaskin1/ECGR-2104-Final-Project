#define CARD_H
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

class card
{
	public:
		card();
		card(int face_value, int suit);
		int getType();
		int getValue();
		int getSuit();
		void printCard();
	private:
		int face; // 1 - 13 (Ace to King)
		int point;
		int suit; //1 - heart, 2- diamond, 3 - club, 4 - spade
};

class deckofCards
{
	public:
		deckofCards();
		void shuffleDeck();
		card dealCard();
		void printDeck();
	private:
		vector<card> deck;
		
};

card::card() {

}

card::card(int face_value, int suit_value) {
	face = face_value;
	suit = suit_value;
	if (face_value < 11) {
		point = face_value;
	}
	else {
		point = 10;
	}
}

int card::getType() {
	return face;
}

int card::getValue() {
	return point;
}

int card::getSuit() {
	return suit;
}

void card::printCard() {
	
	string value;
	string type;
		
	if (face == 1) {
		value = "Ace";
	}
	else if (face == 2) {
		value = "2";
	}
	else if (face == 3) {
		value = "3";
	}
	else if (face == 4) {
		value = "4";
	}
	else if (face == 5) {
		value = "5";
	}
	else if (face == 6) {
		value = "6";
	}
	else if (face == 7) {
		value = "7";
	}
	else if (face == 8) {
		value = "8";
	}
	else if (face == 9) {
		value = "9";
	}
	else if (face == 10) {
		value = "10";
	}
	else if (face == 11) {
		value = "Jack";
	}
	else if (face == 12) {
		value = "Queen";
	}
	else if (face == 13) {
		value = "King";
	}
	else {
		value = "error";
	}

	if (suit == 1) {
		type = "Hearts";
	}
	else if (suit == 2) {
		type = "Diamonds";
	}
	else if (suit == 3) {
		type = "Clubs";
	}
	else if (suit == 4) {
		type = "Spades";
	}
	else {
		type = "ERROR";
	}

	cout << value << " of " << type << endl;
}
		
deckofCards::deckofCards() {
	for(int x = 1; x < 5; x++) {
		for(int y = 1; y < 14; y++) {
			card card1(y,x);
			deck.push_back(card1);
		}
	}
}

void deckofCards::printDeck() {
	for(int i = 0; i < 52; i++) {		
		deck[i].printCard();
	}
}

void deckofCards::shuffleDeck() {
    for(int first = 0; first < 52; first++)
    {
        int second = (rand() + time(0))% 52;
        card temp = deck[first];
        deck[first] = deck[second];
        deck[second]= temp;
    }
}

card deckofCards::dealCard() {
	card card1;

	card1 = deck.begin();
	deck.erase(deck.begin());

	return card1;
}


