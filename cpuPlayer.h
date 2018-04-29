#ifndef CPUPLAYER_H
#define CPUPLAYER_H
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class cpuPlayer {
	public:
		cpuPlayer();
		cpuPlayer(vector <int> hand1);
		void chooseDrawPile();
		void chooseDiscard();
		void chooseKnock();
	private:
		vector<int> hand;
}

#endif

