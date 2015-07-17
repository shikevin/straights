#include "GameState.h"

using namespace std;

const Card GameState::startCard = Card(SPADE, SEVEN);
GameState::GameState() {
}


vector<Player*> GameStategetPlayersInGame() {
    return playersInGame;
}

int GameState::getCurrentPlayerID() {
	return currentPlayer->getPlayerID();
}

string GameState::getCurrentPlayerType() {
	return currentPlayer->getPlayerType();
}

void GameState::updateCurrentPlayer(Player* newCurrentPlayer) {
	currentPlayer = newCurrentPlayer;
}
