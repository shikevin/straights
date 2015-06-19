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

void Table::playGame(string choices) {
    // start up the game
    initializePlayers(choices);
    deck.newRound();
    //
    // TO-DO reset player hands to nothing before distributing
    //
    distributeCards();
    int start = findStartingPlayer();

    Print information = Print();
    information.notifyStart(start);

 
    while (!isGameOver()) {
        // play the game
        Player* playaPointa = playersInGame[currentPlayer];
        Command validCommand;
    	if(playaPointa->getPlayerType() == "h") {

    		//print cards on table
    		information.printCardsOnTable(deck);
    		//print player's hand
    		information.printHumanHand(*playaPointa);
    		//print legal plays
    		bool playableCardExists = information.printLegalPlays(*playaPointa, deck);
            validCommand = getHumanCommand(playableCardExists);
    	} else {
    		//generate commands for computers
    	
    	}
        executeMove(validCommand);
	incrementCurrentPlayer();
    }
}

void Table::executeMove(Command move) {
    Player* playerPointer = playersInGame[currentPlayer];
    if (move.type == PLAY) {
        playerPointer->play(move.card);
        deck.play(move.card);
    } else if(move.type == DISCARD) {
    	playerPointer->discard(move.card);
    	scoreboard.discard(currentPlayer,move.card);
    } else if(move.type == RAGEQUIT) {
    	*playerPointer = playerPointer->ragequit();
    }
}

Command Table::getHumanCommand(bool playableCardExists) {
    Player *playaPointa = playersInGame[currentPlayer];
    // Read plays by player
    Command humanInput = Command();
    cout << ">";
    cin >> humanInput;
    if (playableCardExists) { // player must play legal card
        while (humanInput.type == DISCARD || 
                !playaPointa->hasCard(humanInput.card) ||
                (humanInput.type == PLAY &&
                 !deck.isCardPlayable(humanInput.card))) {
            if (humanInput.type == DISCARD) {
                cout << "You have a legal play. You may not discard." << endl;
            } else {
                cout << "This is not a legal play." << endl;
            }
            cout << ">";
            cin >> humanInput;
        }
    } else { // player must discard 
        while ((humanInput.type == PLAY) ||
                !playaPointa->hasCard(humanInput.card)) {
            cout << "This is not a legal play." << endl;
            cout << ">";
            cin >> humanInput;
        }
    }
    return humanInput;
}

void Table::incrementCurrentPlayer() {
	currentPlayer++;
	currentPlayer %= 4;
}
