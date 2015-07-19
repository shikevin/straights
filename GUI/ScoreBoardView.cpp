#include "ScoreBoardView.h"
#include "Player.h"
#include <string>
#include <ostream>

using namespace std;

ScoreBoardView::ScoreBoardView():ViewComponent() {

//Gtk::Label labelArray[NUM_PLAYERS];



for(int i = 0; i < NUM_PLAYERS; i++) {

	rageButtons[i].set_label("RAGEQUIT");

	string result = generateLabelMessage(i,0,0);
	playerStats[i].set_text(result);

	playerBoxes[i].add(playerStats[i]);
	playerBoxes[i].add(rageButtons[i]);

	
	scoresBox.pack_start(playerBoxes[i]);
}

	scoresBox.show();
}

ScoreBoardView::~ScoreBoardView() {}

void ScoreBoardView::updateView() {
	//update labels for each of the boxes

	//query gamestate for current player's numdiscards 
	//query scoreboard for currentplayer's score
	Player* currentPlayer = gamestate->getCurrentPlayer();

	int playerID = currentPlayer->getPlayerID();
	int currentScore = scoreboard->getCurrentScore(playerID);
	int numDiscards = currentPlayer->getNumDiscardedCards();

	string result = generateLabelMessage(playerID,currentScore,numDiscards);
	playerStats[playerID].set_text(result);
	cout << "Segfault 2" << endl;
}

string ScoreBoardView::generateLabelMessage(int playerID, int playerScore, int numDiscards) {

	cout << "Segfault " << endl;
	
	string player ="\nPlayer ";
	string score = "\nScore: ";
	string discards = "\nDiscards: ";

	stringstream playerInfo;
	playerInfo << player << playerID+1 << score << playerScore << discards << numDiscards << endl;
	string result = playerInfo.str();
cout << "Segfault 1" << endl;
	return result;

}

Gtk::HBox* ScoreBoardView::getScoreBox() {
	return &scoresBox;
}
