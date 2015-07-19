#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include <string>
#include "Card.h"


//behaves like the oberserver header


class Player {

public:
	explicit Player(std::string); //type of player and player's round get passed in to initialize a player
	explicit Player(std::string, int); //type of player and player's round get passed in to initialize a player
	virtual ~Player() {} //default is good enough?
		
	std::vector<Card*> getCardsInHand() const;
    std::vector<Card*> getDiscardedCards() const;
	virtual void play(Card&) = 0;		
	void discard(Card*);
    bool hasCard(const Card&);
	std::string getPlayerType(); // "h" v. "c"
	int getNumDiscardedCards();
	int getPlayerID();
	void addCardToHand(Card*);
    void newRound();


protected:
	void removeCardFromHand(Card&);
	std::string type;
	std::vector<Card*> cardsInHand;
	std::vector<Card*> cardsDiscarded;
    static int next_;
	int playerID; //0..3
};




#endif
