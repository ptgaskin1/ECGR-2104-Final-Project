#include "card.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {

vector<card> player_hand;

deckofCards deck;
deck.printDeck();
deck.shuffleDeck();
cout << endl;
cout << "Shuffled deck\n";
deck.printDeck();
cout << endl;

player_hand = deck.dealCard();

player_hand[0].printCard();


return 0;
}
