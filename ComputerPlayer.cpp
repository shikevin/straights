#include "ComputerPlayer.h"
#include  <vector>
#include <string>
using namespace std;


ComputerPlayer::ComputerPlayer(string playerType) : Player(playerType) {}

ComputerPlayer::ComputerPlayer(string playerType, int id) : Player(playerType, id) {}


void ComputerPlayer::play(Card& playThis) {
	//assuming card played is legal
	//remove from cards in hand
	removeCardFromHand(playThis);

	//add it to table?
}





