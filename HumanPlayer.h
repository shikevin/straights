#ifndef _HUMANPLAYER_
#define _HUMANPLAYER_

#include <vector>
#include <string>
#include "Player.h"


//behaves like the oberserver header


class HumanPlayer : public Player {

public:
	HumanPlayer(std::string, int); //type of player and player's round get passed in to initialize a player
	void play(Card&);
	//void discard(Card&);
	void quit();
	ComputerPlayer ragequit();
	//std::string getPlayerType(); // "h" v. "c"
	//int getPlayerID();
};




#endif
