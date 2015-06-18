#include "Table.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <vector>
#include <string>
using namespace std;


int Table::id = 1;

int generateID() {

	int temp = Table::id;
	
	if(Table::id == 4) {
		Table::id = 1;
	} else {
		Table::id++;
	}

	return temp;
}

Table::Table() {
	playersInGame.reserve(4);
	scoreboard = Scoreboard();
	deck = Deck();
}

void Table::initializePlayers(string choices) {
	for(int i = 0; i < choices.size(); i++) {
		if(choices.at(i) == 'h') {
			HumanPlayer human = HumanPlayer("h",generateID());
			playersInGame.push_back(&human);
		} else {
			ComputerPlayer computer = ComputerPlayer("c",generateID());
			playersInGame.push_back(&computer);
		}
	}
}
