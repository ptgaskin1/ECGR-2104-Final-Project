#include "deckofcards.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
    deckofcards deck;
    card currentcard;
    deck.printdeck();
    deck.shuffle();
    cout<< endl << endl;
    deck.printdeck();
    deck.shuffle();
    cout << endl << endl;
    for(int i=0;i < 52; i++)
    {
        currentcard = deck.dealcard();
        cout << currentcard.print() << endl;
    }
    return 0;
}
