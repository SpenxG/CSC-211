#include <string>
#include <iostream>

#ifndef card
#define card



const int COLOR_MAX(2);
const int SUIT_MAX(4);
const int RANK_MAX(13);

class Card {
	
public:

	Card () {
		rank = 0;
	}
	
	Card (std::string c, std::string s, std::string r){
		color = c;
		suit = s;
		rank = r;
		std::cerr << "Card not valid" << std::endl;
	}
	
	
	


	std::string color;
	std::string suit;
	std::string rank;
	
	std::string 
	
	std::string get_color();
	std::string get_suit();
	std::string get_rank();
	
};

#endif