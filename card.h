#ifndef card_H
#define card_H
#include <string>
#include <iostream>
using namespace std;

class card
{
   public:
       card(string cardFace, string cardSuit);
       string print();
       card();
   private:
    string face;
    string suit;
    int point_value;
	int face_value;
};

card::card()
{

}

card::card(string cardFace, string cardSuit)
{
    face = cardFace;
    suit = cardSuit;
    if(face == "A") {
		face_value = 1;
		point_value = face_value;
	}
	else if(face == "2") {
		face_value = 2;
		point_value = face_value;
	}
	else if(face == "3") {
		face_value = 3;
		point_value = face_value;
	}
	else if(face == "4") {
		face_value = 4;
		point_value = face_value;
	}
	else if(face == "5") {
		face_value = 5;
		point_value = face_value;
	}
	else if(face == "6") {
		face_value = 6;
		point_value = face_value;
	}
	else if(face == "7") {
		face_value = 7;
		point_value = face_value;
	}
	else if(face == "8") {
		face_value = 8;
		point_value = face_value;
	}
	else if(face == "9") {
		face_value = 9;
		point_value = face_value;
	}
	else if(face == "10") {
		face_value = 10;
		point_value = face_value;
	}
	else if(face == "J") {
		face_value = 11;
		point_value = 10;
	}
	else if(face == "Q") {
		face_value = 12;
		point_value = 10;
	}
	else if(face == "K") {
		face_value = 13;
		point_value = 10;
	}
	

}

string card:: print()
{
    return (face + "/" +suit);
}
#endif
