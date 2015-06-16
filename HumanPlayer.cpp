#include "HumanPlayer.h"
#include  <vector>
#include <string>
using namespace std;


HumanPlayer::HumanPlayer(string playerType, int id) : Player(playerType,id) {}


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

ComputerPlayer HumanPlayer::ragequit() {
	//create computer player with current deck
	//outside code replaces human player with this new computer player
	ComputerPlayer * replacementPlayer = ComputerPlayer(this->getPlayerType(), this->getPlayerID());
	//initilize computerplayer's arrays
	for(int i =0; i < this->cardsInHand.size(); i++) {
		replacementPlayer->addCardToHand(this->cardsInHand[i]);
	}

}





