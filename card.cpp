#include "deckofcards.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
    deckofcards deck;
    card currentcard;
    cout << "ordered deck"<<endl;
    deck.printdeck();
    deck.shuffle();
    cout<< endl << endl;
    cout<< "shuffled deck"<<endl;

    deck.printdeck();
  //  deck.shuffle();
    cout << endl << endl;
    cout<< "Player 1"<<endl;
    for(int i=0;i < 10; i++)
    {
        currentcard = deck.dealcard();
        cout << currentcard.print() << endl;
    }

    cout << endl << endl;
    cout<< "Player 2"<<endl;
     for(int i=11;i<20; i++ )
    {
        currentcard = deck.dealcard();
        cout << currentcard.print() << endl;
    }


    cout << endl << endl;
    cout << "rest of deck"<<endl;
    for(int i=21;i<52; i++ )
    {
        currentcard = deck.dealcard();
        cout << currentcard.print() << endl;
    }



  /*  vector<int>newDeck(){ // creates the vector to hold all 52 cards

	vector <int>deck;

	for (int i = 0; i <52; ++i){

		deck.push_back(i);

		}*/
    return 0;
}
