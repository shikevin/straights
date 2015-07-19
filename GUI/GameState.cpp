#include "GameState.h"
#include <iostream>

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

bool GameState::isFirstPlayer() const {
    return firstPlayer;
}

void GameState::incrementPlayer() {
    currentPlayer++;
    currentPlayer %= playersInGame.size();
    // next round, figure out next player
    // set currentPlayer to nextPlayer
    firstPlayer = false;
    notify();
}

void GameState::findFirstPlayer() {
    for (int i = 0; i < playersInGame.size(); i++) {
        if (playersInGame[i]->hasCard(startCard)) {
            currentPlayer = playersInGame[i]->getPlayerID();
            return;
        }
    }
    currentPlayer = -1;
}

void GameState::newGame() {
    firstPlayer = true;
    findFirstPlayer();
    notify();
}

void GameState::rageQuitPlayer() {
    Player* player;
    Player* temp = playersInGame[currentPlayer];
    player = static_cast<HumanPlayer*>(playersInGame[currentPlayer])->ragequit();
    playersInGame[currentPlayer] = player;
    delete temp;
}
void GameState::subscribe(ViewComponent* newComponent) {
	myViewComponents.push_back(newComponent);
}

string GameState::getPlayerType() {
    return playersInGame[currentPlayer]->getPlayerType();
}

void GameState::notify() {
	for(int i = 0; i < myViewComponents.size(); i++) {
		myViewComponents[i]->updateView();
	}
}

Player* GameState::getCurrentPlayer() const{
    return playersInGame[currentPlayer];
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
