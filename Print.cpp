#include "Print.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Print::Print() {
}

void Print::notifyStart(int player) {
    cout << "A new round begins. It's player " + to_string(player + 1) + "'s turn to play." << endl;

}

void Print::printCardsOnTable(const Deck& printDeck) {
	cout << "Cards on the table:" << endl << printDeck;
}

void Print::printHumanHand(const Player& printPlayerHand) {
	cout << "Your hand: ";
    vector<Card*> playerCards = printPlayerHand.getCardsInHand();
	for(int i = 0; i < playerCards.size(); i++) {
		cout << *playerCards[i] << " ";
	}
    cout << endl;
}

bool Print::printLegalPlays(const Player& player, const Deck& deck) {
    bool legalCardExists = false;
    cout << "Legal plays: ";
    vector<Card*> playerCards = player.getCardsInHand();
    for (int i = 0; i < playerCards.size(); i++) {
        if (deck.isCardPlayable(*playerCards[i])) {
            cout << *playerCards[i] << " ";
            legalCardExists = true;
        }
    }
    cout << endl;
    return legalCardExists;
}

void Print::printMove(int player, const Command& move) {
    string moves[2] = {"plays", "discards"};
    cout << "Player " << to_string(player + 1) << " " << 
        moves[move.type] << " " << move.card << "." << endl;
}
