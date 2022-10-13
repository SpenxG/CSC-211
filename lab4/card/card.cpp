#include <stdlib.h>
#include "card.h"
#include <iostream>
using namespace std;

const std::string color[COLOR_MAX] = {"Red", "Black"};
const std::string suit[SUIT_MAX] = {"Spades", "Hearts", "Diamonds", "Clubs"};
const std::string rank[RANK_MAX] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};




string Card::get_color() {
	return color = rand() % (COLOR_MAX);
}

string Card::get_suit() {
	return suit = rand() % (SUIT_MAX);
}

string Card::get_rank() {
	return rank = rand() % (RANK_MAX);
}



