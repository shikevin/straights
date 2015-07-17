#ifndef _TABLE_
#define _TABLE_

#include "Player.h"
#include "Scoreboard.h"
#include "Deck.h"
#include <vector>
#include <string>
#include "Command.h"
#include "Print.h"
#include "Input.h"

/*
responsible for controlling aspects of the game

main creates the object Table

Table has a list of players
Table has a scoreboard
Table has a deck
 */

class Table {
public:
	Table(int);
    ~Table();
    void playGame(std::string choices);

private:
    bool isRoundOver();
    void executeMove(Command, bool);
    static const Card startCard;
	std::vector<Player*> playersInGame;
    bool isGameOver();
    void distributeCards();
    int findStartingPlayer();
	void initializePlayers(std::string); // string passed in is "choices" from main
	int currentPlayer;
	void incrementCurrentPlayer();
    Command getComputerCommand(bool);
    Command getHumanInput(bool, bool);
    Input* input;
    Print* information;
	Deck* deck;
	Scoreboard* scoreboard;
};
#endif
