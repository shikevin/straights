#include "Player.h"
#include  <vector>
#include <iostream>
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

void Player::discard(Card* discardThisCard) {
	//simply removes card from player's play deck and adds it to the discardedDeck
	removeCardFromHand(*discardThisCard);
	cardsDiscarded.push_back(discardThisCard);
}

string Player::getPlayerType() {
	return this->type;
}

int Player::getPlayerID() {
	return this->playerID;
}

void Player::removeCardFromHand(Card& cardToRemove) {
    vector<Card*>::iterator it;
    for (it = cardsInHand.begin(); it != cardsInHand.end(); it++) {
        if (cardToRemove == *(*it)) {
            cardsInHand.erase(it);
            return;
        }
    }
}

void Player::newRound() {

    cardsInHand.clear();
    cardsDiscarded.clear();
}

int Player::getNumDiscardedCards() {
    int counter = 0;
    cout << "Segfault 4" << endl;
    for(int i = 0; i < cardsDiscarded.size(); i++) {
        if(cardsDiscarded[i]) {
            counter++;
        }
    }
    cout << "Segfault 5" << endl;
    return counter;
}



void Player::addCardToHand(Card *newCard) {
	cardsInHand.push_back(newCard);
}

vector<Card*> Player::getCardsInHand() const {
    return cardsInHand;
}

vector<Card*> Player::getDiscardedCards() const {
	return cardsDiscarded;
}

bool Player::hasCard(const Card& card) {
    for (int i =0 ; i < cardsInHand.size(); i++) {
        if (card == *cardsInHand[i]) {
            return true;
        }
    }
    return false;
}
