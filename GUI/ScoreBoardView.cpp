#include "ScoreBoardView.h"
#include <string>

ScoreBoardView::ScoreBoardView():Component(), player1Label("Player 1\n\nScore: 0\nDiscards: 0\n"), player2Label("Player 2\n\nScore: 0\nDiscards: 0\n"), player3Label("Player 3\n\nScore: 0\nDiscards: 0\n"), player4Label("Player 4\n\nScore: 0\nDiscards: 0\n") {


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
}

Gtk::HBox* ScoreBoardView::getScoreBox() {
	return &scoresBox;
}
