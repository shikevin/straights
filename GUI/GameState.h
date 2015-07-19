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
    void newRound();
    void rageQuitPlayer();
    Player* getCurrentPlayer() const;
    bool isFirstPlayer() const;
    std::string getPlayerType();
    void incrementPlayer();
    static const Card startCard;
    void notify();
//    void nextPlayer();

private:
	int currentPlayer;
	std::vector<Player*> playersInGame;
    void findFirstPlayer();
    std::vector<ViewComponent*> myViewComponents;
    bool firstPlayer;
//    int currentPlayer;
};

#endif
