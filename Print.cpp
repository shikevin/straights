#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

Print::Print() {
}

void Print::notifyStart(int player) {
    cout << "A new round begins. It's player " + to_string(player) + "'s turn to play." << endl;

}

void Print::printCardsOnTable(const Deck& printDeck) {
	cout << "Cards on the table:" << endl << printDeck;
}

void Print::printHumanHand(const Player& printPlayerHand) {
	cout << "Your hand: ";
	for(int i = 0; i < printPlayerHand.cardsInHand.size(); i++) {
		cout << printPlayerHand.cardsInHand[i] << " ";
	}
}

void Print::printLegalPlays() {

}
