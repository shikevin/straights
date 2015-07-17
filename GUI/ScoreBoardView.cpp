#include "ScoreBoardView.h"
#include <string>

ScoreBoardView::ScoreBoardView(): player1Label("Player 1\n\nScore:\nDiscards:\n") {

	//initialize titles of buttons, add to view


//init seperate boxes for players
	scoresBox.pack_start(player1Box);


	scoresBox.pack_start(player2Box);


	scoresBox.pack_start(player3Box);


	scoresBox.pack_start(player4Box);




//add buttons to those boxes
	player1Box.add(player1Label);
	player1Box.add(rageButtons[0]);
	//player1subBox.pack_start(rageButtons[0]);
	//player1Box.add(player1subBox);


	player2Box.add(rageButtons[1]);


	player3Box.add(rageButtons[2]);


	player4Box.add(rageButtons[3]);


//add labels for scores and discards to the player's boxes




	for(int i = 0; i < 4; i++) {
		rageButtons[i].set_label("HULK MODE");
	}

	scoresBox.show();

}

ScoreBoardView::~ScoreBoardView() {}




Gtk::HBox* ScoreBoardView::getScoreBox() {
	return &scoresBox;
}