#ifndef _TABLE_
#define _TABLE_

#include "Player.h"
#include "Scoreboard.h"
#include "Deck.h"
#include <vector>
#include <string>

/*
responsible for controlling aspects of the game

main creates the object Table

Table has a list of players
Table has a scoreboard
Table has a deck
 */

class Table {
public:
	Scoreboard scoreboard;

	Table();
    void startGame(std::string choices);

private:
    static const Card startCard;
	std::vector<Player*> playersInGame;
	Deck deck;
    void distributeCards();
    int findStartingPlayer();
	void initializePlayers(std::string); // string passed in is "choices" from main
	static int id;
	friend int generateID();




};








#endif
