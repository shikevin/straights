#include "ScoreBoardView.h"
#include <string>

using namespace std;

ScoreBoardView::ScoreBoardView():ViewComponent(), player1Label("\nPlayer 1\n\nScore: 0\nDiscards: 0\n"), player2Label("\nPlayer 2\n\nScore: 0\nDiscards: 0\n"), player3Label("\nPlayer 3\n\nScore: 0\nDiscards: 0\n"), player4Label("\nPlayer 4\n\nScore: 0\nDiscards: 0\n") {


string player ="\nPlayer\n";
string score = "\nScore: ";
string discards = "\nDiscards: ";



for(int i = 0; i < NUM_PLAYERS; i++) {

	stringstream playerStats;
	playerStats << player << i+1 << score << 0 << discards << 0 << endl;
	string result = playerStats.str();


	labels[i].set_text(result);
	//playerBoxes.push_back(Gtk::VBox y);
	rageButtons[i].set_label("RAGEQUIT");






}


//init seperate boxes for players
	scoresBox.pack_start(player1Box);
	scoresBox.pack_start(player2Box);
	scoresBox.pack_start(player3Box);
	scoresBox.pack_start(player4Box);

//add buttons and labels to those boxes
	player1Box.add(player1Label);
	player1Box.add(rageButtons[0]);

	player2Box.add(player2Label);
	player2Box.add(rageButtons[1]);

	player3Box.add(player3Label);
	player3Box.add(rageButtons[2]);

	player4Box.add(player4Label);
	player4Box.add(rageButtons[3]);


	for(int i = 0; i < 4; i++) {
		rageButtons[i].set_label("HULK MODE");
	}

	scoresBox.show();

}

ScoreBoardView::~ScoreBoardView() {}

void ScoreBoardView::updateView() {
	//update labels for each of the boxes

}

Gtk::HBox* ScoreBoardView::getScoreBox() {
	return &scoresBox;
}
