#include "card.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main() {

int input1;
int input2;

card card1(1, 4);

card1.printCard();

cout << card1.getValue() << endl;

cout << "Enter face value: ";
cin >> input1;
cout << "Enter suit value: ";
cin >> input2;

card card2(input1, input2);

card2.printCard();

cout << card2.getValue() << endl;


return 0;
}
