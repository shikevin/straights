#ifndef _TABLE_
#define _TABLE_

#include "Player.h"
#include "Scoreboard.h"
#include "Deck.h"
#include "Command.h"
#include <vector>
#include <string>
#include "component.h"
#include "GameState.h"

/*
responsible for controlling aspects of the game

main creates the object Table

Table has a list of players
Table has a scoreboard
Table has a deck
 */

class TableController {
public:
	TableController(int, std::vector<ViewComponent*>);
    ~TableController();
    void playGame(std::string choices);

private:
    bool isRoundOver();
    void executeMove(Command);
//    static const Card startCard;
//	std::vector<Player*> playersInGame;
//    bool isGameOver();
    void distributeCards();
//    int findStartingPlayer();
//	void initializePlayers(std::string); // string passed in is "choices" from main
	//void incrementCurrentPlayer();
    Command generateComputerCommand();
   // Command getHumanInput(bool, bool);
    void handleComputerMove();
	Deck* deck;
	Scoreboard* scoreboard;
    GameState* gameState;
};
#endif
