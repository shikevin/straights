#ifndef __GAME_STATE_H
#define __GAME_STATE_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <vector>
#include <string>
#include "Card.h"
#include "Subject.h"

class Subject;

class GameState:public Subject{
public: 
    GameState();
    ~GameState();
    void initializePlayers(std::string);
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
//    int currentPlayer;
};

#endif
