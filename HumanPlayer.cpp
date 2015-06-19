#include "HumanPlayer.h"
#include  <vector>
#include <string>
#include <iostream>
using namespace std;


HumanPlayer::HumanPlayer(string playerType) : Player(playerType) {}


void HumanPlayer::play(Card& playThis) {
	//assuming card played is legal
	//remove from cards in hand
	removeCardFromHand(playThis);

	//add it to table?
}

void HumanPlayer::quit() {
	//end game
	//just break everything
}

ComputerPlayer* HumanPlayer::ragequit() {
	//create computer player with current deck
	//outside code replaces human player with this new computer player
	ComputerPlayer* replacementPlayer = new ComputerPlayer("c", this->getPlayerID());
	//initilize computerplayer's arrays
	for(int i =0; i < this->cardsInHand.size(); i++) {
		replacementPlayer->addCardToHand((this->cardsInHand[i]));
	}
	return replacementPlayer;

}





