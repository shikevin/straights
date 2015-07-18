#ifndef __GAME_STATE_H
#define __GAME_STATE_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "component.h"
#include <vector>
#include <string>
#include "Card.h"

class ViewComponent;

class GameState {
public: 
    GameState();
    ~GameState();
    void initializePlayers(std::string);
    void subscribe(ViewComponent*);
//	int getCurrentPlayerID();
//    std::string getCurrentPlayerType();
//	void updateCurrentPlayer( Player*);
	std::vector<Player*> getPlayersInGame();
    void newGame();
//    void nextPlayer();

private:
	Player* currentPlayer;
    static const Card startCard;
	std::vector<Player*> playersInGame;
    void findFirstPlayer();
    void notify();
    std::vector<ViewComponent*> myViewComponents;
//    int currentPlayer;
};

#endif
