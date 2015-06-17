#include "Player.h"
#include  <vector>
#include <string>
using namespace std;


static int Player::id = 1;

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

void Player::addCardToHand(Card& newCard) {
	Card * temp = &newCard;
	cardsInHand.push_back(temp);
}

int generateID() {

	int temp = id;
	
	if(id == 4) {
		id = 1;
	} else {
		id++;
	}

	return temp;
}





