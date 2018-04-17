#ifndef card_H
#define card_H
#include <string>
#include <iostream>
using namespace std;

class card
{
   public:
       card(string cardFace, string cardSuit);
       string print() const;
       card();
   private:
    string face;
    string suit;
};

card::card()
{

}

card::card(string cardFace, string cardSuit)
{
    face = cardFace;
    suit = cardSuit;
}

string card:: print() const
{
    return (face + "of" +suit);
}
#endif
