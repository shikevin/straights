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
#include "validate.h"
#include "mainwindow.h"

class TableController {
public:
	TableController(std::vector<ViewComponent*>, MainWindow*);
    ~TableController();
    void playGame(int, std::string choices);
    void playerCommand(Command);

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
    void nextPlayer();
    bool doesPlayableCardExist();
    bool isGameOver();
	Deck* deck;
	Scoreboard* scoreboard;
    Validate* validation;
    GameState* gameState;
    MainWindow* mainWindow;
};
#endif
