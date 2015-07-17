#include "GameState.cpp"

using namespace std;

int GameState::getPlayerID() {
	return currentPlayer->getPlayerID();
}

string GameState::getPlayerType() {
	return currentPlayer->getPlayerType();
}

void GameState::updateCurrentPlayer(Player* newCurrentPlayer) {
	currentPlayer = newCurrentPlayer;
}