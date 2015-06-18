#include "Card.h"
#include "Table.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Print.h"
#include <vector>
#include <string>
using namespace std;

const Card Table::startCard = Card(SPADE, SEVEN);

Table::Table() {
	playersInGame.reserve(4);
	scoreboard = Scoreboard();
	deck = Deck();
}

int Table::findStartingPlayer() {
    for (int i = 0; i < 4; i++) {
        if (playersInGame[i]->hasCard(startCard)) {
            return i+1;
        }
    }
    throw "CRASH CRASH CRASH";
}

void Table::distributeCards() {
    Card** shuffled = deck.getDeck();  

    for (int i = 1; i <=4 ; i++) {
        for (int j = 1; j <=13; j++) {
            playersInGame[i-1]->addCardToHand(shuffled[i*j-1]);
        }
    }
}

void Table::startGame(string choices) {
    // start up the game
    initializePlayers(choices);
    deck.newRound();
    distributeCards();
    int start = findStartingPlayer();

    Print information = Print();
    information.notifyStart(start);

     
}

void Table::initializePlayers(string choices) {
	for(int i = 0; i < choices.size(); i++) {
		if(choices.at(i) == 'h') {
			HumanPlayer human = HumanPlayer("h");
			playersInGame.push_back(&human);
		} else {
			ComputerPlayer computer = ComputerPlayer("c");
			playersInGame.push_back(&computer);
		}
	}
}
