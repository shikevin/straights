#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include <string>
#include "Card.h"


//behaves like the oberserver header


class Player {

public:
	explicit Player(std::string, int); //type of player and player's round get passed in to initialize a player
	//~Player(); //default is good enough?
		
	virtual void play(Card&) = 0;		
	void discard(Card&);

	std::string getPlayerType(); // "h" v. "c"
	int getPlayerID();
	void addCardToHand(Card&);

protected:
	void removeCardFromHand(Card&);
	std::string type;
	std::vector<Card*> cardsInHand;
	std::vector<Card*> cardsDiscarded;
	int playerID; //1..4
};




#endif
