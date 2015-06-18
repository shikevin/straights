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
	std::vector<Player*> playersInGame;
	Scoreboard scoreboard;
	Deck deck;

	Table();
	void initializePlayers(std::string); // string passed in is "choices" from main
	int findPlayerWithSpades(); //returns id of player with 7 of spades

private:
	static int id;
	friend int generateID();




};








#endif