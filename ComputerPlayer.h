#ifndef _COMPUTERPLAYER_
#define _COMPUTERPLAYER_

#include <string>
#include "Player.h"


//behaves like the oberserver header


class ComputerPlayer : public Player {

public:
	ComputerPlayer(std::string, int); //type of player and player's round get passed in to initialize a player
	void play(Card&);
};




#endif
