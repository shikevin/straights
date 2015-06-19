#include "Player.h"
#include  <vector>
#include <string>
using namespace std;

int Player::next_ = 0;

Player::Player(string playerType) : type(playerType) {
    playerID = next_++;
	cardsInHand.reserve(13);
	cardsDiscarded.reserve(13);
}

Player::Player(string playerType, int id) : type(playerType), playerID(id) {
	cardsInHand.reserve(13);
	cardsDiscarded.reserve(13);
}

void Player::discard(Card& discardThisCard) {
	//simply removes card from player's play deck and adds it to the discardedDeck
	Card * temp = &discardThisCard;
	removeCardFromHand(*temp);
	//removed from played cards
	//add to discardedcards
	cardsDiscarded.push_back(temp);
}

string Player::getPlayerType() {
	return this->type;
}

int Player::getPlayerID() {
	return this->playerID;
}

void Player::removeCardFromHand(Card& cardToRemove) {

	Card * temp = &cardToRemove;
	for(int i = 0; i < cardsInHand.size(); i++) {
		if(temp == cardsInHand[i]) {
			//remove this pointer
			cardsInHand[i] = NULL;
			//make pointer point to nothing
		}
	}
}

void Player::addCardToHand(Card *newCard) {
	cardsInHand.push_back(newCard);
}
