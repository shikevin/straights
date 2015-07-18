#include "GameState.h"

using namespace std;

const Card GameState::startCard = Card(SPADE, SEVEN);

GameState::GameState() {
}

GameState::~GameState() {
    for (int i = 0; i < playersInGame.size(); i++) {
        delete playersInGame[i];
        playersInGame[i] = NULL;
    }
}

void GameState::initializePlayers(string choices) {
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

void GameState::findFirstPlayer() {
    for (int i = 0; i < playersInGame.size(); i++) {
        if (playersInGame[i]->hasCard(startCard)) {
            currentPlayer = playersInGame[i];
        }
    }
    currentPlayer = NULL;
}

void GameState::newGame() {
    findFirstPlayer();
    notify();
}

// GameState::GameState() {
// }
// 
// 
vector<Player*> GameState::getPlayersInGame() {
    return playersInGame;
}
// 
// int GameState::getCurrentPlayerID() {
// 	return currentPlayer->getPlayerID();
// }
// 
// string GameState::getCurrentPlayerType() {
// 	return currentPlayer->getPlayerType();
// }
// 
// void GameState::updateCurrentPlayer(Player* newCurrentPlayer) {
// 	currentPlayer = newCurrentPlayer;
// }
