#ifndef deckofcards_h
#define deckofcards_h
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int cards_per_deck = 52;

class deckofcards
{
public:
    deckofcards();
    void shuffle();
    card dealcard();
    void printdeck() const;

private:
    card *deck;
    int currentcard;
};

void deckofcards::printdeck() const
{
   cout<<left;
   for(int i =0; i < cards_per_deck; i++)
   {
       cout<<setw(19)<<deck[i].print();
       if((i+1)%4 ==0)
        cout<<endl;
   }
}

deckofcards::deckofcards()
{
    string faces[]={"Ace","2","3","4","5","6","7","8","9","10","J","Q,","K"};
    string suits[]= {"hearts", "diamonds", "clubs", "spades"};
    deck= new card[cards_per_deck];
    currentcard = 0;
    for(int count =0; count < cards_per_deck; count++)
        deck[count] = card(faces[count % 13], suits[count/13]);
}
void deckofcards::shuffle()
{
    currentcard = 0;
    for(int first = 0; first < cards_per_deck; first++)
    {
        int second = (rand() + time(0))% cards_per_deck;
        card temp = deck[first];
        deck[first] = deck[second];
        deck[second]= temp;
    }
}
card deckofcards::dealcard()
{
    if(currentcard > cards_per_deck)
        shuffle();
    if(currentcard< cards_per_deck)
        return (deck[currentcard++]);
    return (deck[0]);
}
#endif // deckofcards_h
