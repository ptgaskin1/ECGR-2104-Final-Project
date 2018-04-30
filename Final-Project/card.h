#define CARD_H
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class card
{
	public:
		card();
		card(int rank_value, int suit_value);
		int getRank();
		int getValue();
		int getSuit();
		void printCard();
		//void checkMeld();
	private:
		int rank; // 0 - 12 (Ace to King)
		int point;
		int suit; //0 - spades, 1 - hearts, 2 - diamonds, 3 - clubs
		string image;
		bool inMeld;
};

card::card() {
	rank = 0;
	suit = 0;
	point = 1;
}

card::card(int rank_value, int suit_value) {
	rank = rank_value;
	suit = suit_value;
	if (rank_value < 9) {
		point = rank_value+1;
	}
	else {
		point = 10;
	}
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
	
	image = deck[rank_value][suit_value];

}

int card::getRank() {
	return rank;
}

int card::getValue() {
	return point;
}

int card::getSuit() {
	return suit;
}

void card::printCard() {
	cout << image;
	
}
	
