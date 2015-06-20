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

Table::Table(int seed) {
    input = new Input();
	deck = new Deck(seed);
	playersInGame.reserve(4);
    information = new Print();
	scoreboard = new Scoreboard();
	currentPlayer = 0;
}

Table::~Table() {
    for (int i = 0; i < playersInGame.size(); i++) {
        delete playersInGame[i];
        playersInGame[i] = NULL;
    }
    delete deck;
    deck = NULL;
    delete scoreboard;
    scoreboard = NULL;
    delete information;
    information = NULL;
    delete input;
    input = NULL;
}

int Table::findStartingPlayer() {
    for (int i = 0; i < playersInGame.size(); i++) {
        if (playersInGame[i]->hasCard(startCard)) {
            return i;
        }
    }
    return -1;
}

void Table::distributeCards() {
    vector<Card*> shuffled = deck->getDeck();  

    for (int i = 0; i < 4 ; i++) {
        for (int j = 1; j <=13; j++) {
            playersInGame[i]->addCardToHand(shuffled[(13*i)+j-1]);
        }
    }
}

void Table::initializePlayers(string choices) {
	for(int i = 0; i < choices.size(); i++) {
		if(choices.at(i) == 'h') {
			HumanPlayer* human = new HumanPlayer("h");
			playersInGame.push_back(human);
		} else {
			ComputerPlayer* computer = new ComputerPlayer("c");
			playersInGame.push_back(computer);
		}
	}
}

bool Table::isGameOver() {
    for (int i=0; i<playersInGame.size(); i++) {
        if (scoreboard->getCurrentScore(i) + scoreboard->getOldScore(i) >= 80) {
            return true;
        }
    }
    return false;
}

bool Table::isRoundOver() {
    for (int i = 0; i < playersInGame.size(); i++) {
        if (playersInGame[i]->getCardsInHand().size() > 0) {
            return false;
        }
    }
    return true;
}

void Table::playGame(string choices) {
    // start up the game
    initializePlayers(choices);

    try {
        while (!isGameOver()) {
            bool isFirstPlayer = true;
            scoreboard->newRound();
            deck->newRound();
            distributeCards();
            int start = findStartingPlayer();

            currentPlayer = start;
            information->notifyStart(start);
         
            while(!isRoundOver()) {
                // play the game
                Player* playaPointa = playersInGame[currentPlayer];
                Command validCommand;
                if(playaPointa->getPlayerType() == "h") {

                    //print cards on table
                    information->printCardsOnTable(*deck);
                    //print player's hand
                    information->printHumanHand(*playaPointa);
                    //print legal plays
                    bool playableCardExists = information->printLegalPlays(*playaPointa, *deck, isFirstPlayer);
                    validCommand = getHumanInput(playableCardExists, isFirstPlayer);
                } else {
                    //generate commands for computers
                    validCommand = getComputerCommand();
                }
                executeMove(validCommand);
                incrementCurrentPlayer();
                isFirstPlayer = false;
            }

            for (int i = 0; i < playersInGame.size(); i++) {
                information->printPlayerResults(i, scoreboard->getOldScore(i), scoreboard->getCurrentScore(i), playersInGame[i]->getDiscardedCards());
                playersInGame[i]->newRound();
            }
        }
        if (isGameOver()) {
            information->printWinner(scoreboard->getLowestID());
        }
    }
    catch (Input::PlayerQuitException &e) {
    }
}

Command Table::getHumanInput(bool playableCardExists, bool isFirstPlayer) {
    Command validCommand;
    bool success = false;
    while(!success) {
        try {
            validCommand = input->getInput(playableCardExists, *deck, isFirstPlayer, startCard);
            success = true;
        } catch (Input::LegalPlayExistsException &e) {
            cout << "You have a legal play. You may not discard." << endl;
        } catch (Input::IllegalPlayException &e) {
            cout << "This is not a legal play." << endl;
        }
    }
    return validCommand;
}

Command Table::getComputerCommand() {
    vector<Card*> playerCards = playersInGame[currentPlayer]->getCardsInHand();
    Command computerCommand = Command();
    for (int i = 0; i < playerCards.size(); i++) {
        if (deck->isCardPlayable(*playerCards[i])) {
            computerCommand.type = PLAY;
            computerCommand.card = Card(playerCards[i]->getSuit(), playerCards[i]->getRank());
            return computerCommand;
        }
    }
    // discard if no playable card is found
    computerCommand.type = DISCARD;
    computerCommand.card = Card(playerCards[0]->getSuit(), playerCards[0]->getRank());
    return computerCommand;
}

void Table::executeMove(Command move) {
    Player* playerPointer = playersInGame[currentPlayer];
    if (move.type == PLAY) {
        information->printMove(currentPlayer, move);
        playerPointer->play(move.card);
        deck->play(deck->getCard(move.card));
    } else if(move.type == DISCARD) {
        information->printMove(currentPlayer, move);
    	playerPointer->discard(deck->getCard(move.card));
    	scoreboard->discard(currentPlayer, move.card);
    } else if(move.type == RAGEQUIT) {
        information->printRage(currentPlayer);
        Player* temp = playerPointer;
        playerPointer = static_cast<HumanPlayer*>(playerPointer)->ragequit();
        playersInGame[currentPlayer] = playerPointer;
        delete temp;
        executeMove(getComputerCommand());
    }
}


void Table::incrementCurrentPlayer() {
	currentPlayer++;
	currentPlayer %= 4;
}
