#include "Card.h"
#include "Table.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Print.h"
#include "Command.h"
#include <vector>
#include <string>

using namespace std;

const Card Table::startCard = Card(SPADE, SEVEN);

Table::Table() {
	playersInGame.reserve(4);
	scoreboard = Scoreboard();
	deck = Deck();
	currentPlayer = 0;
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

bool Table::isGameOver() {
    for (int i=0; i<playersInGame.size(); i++) {
        if (scoreboard.getCurrentScore(i) + scoreboard.getOldScore(i) >= 80) {
            return true;
        }
    }
    return false;
}

void Table::startGame(string choices) {
    // start up the game
    initializePlayers(choices);
    deck.newRound();
    distributeCards();
    int start = findStartingPlayer();

    Print information = Print();
    information.notifyStart(start);

 
    while (!isGameOver()) {
        // play the game
    	if(playersInGame[currentPlayer]->getPlayerType() == "h") {

    		//print cards on table
    		information.printCardsOnTable(deck);
    		//print player's hand
    		information.printHumanHand(*playersInGame[currentPlayer]);
    		//print legal plays
    		information.printLegalPlays(playersInGame[currentPlayer], deck.getLatestCard());

    	} else {

    	}
 





	incrementCurrentPlayer();
    }
}

void Table::incrementCurrentPlayer() {
	currentPlayer++;
	currentPlayer %= 3;
}
