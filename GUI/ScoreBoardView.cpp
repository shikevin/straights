#include "ScoreBoardView.h"
#include "Player.h"
#include <string>
#include <ostream>
#include "Command.h"

using namespace std;

ScoreBoardView::ScoreBoardView():ViewComponent() {
    for(int i = 0; i < NUM_PLAYERS; i++) {
        rageButtons[i].set_label("RAGEQUIT");
        string result = generateLabelMessage(i,0,0);
        playerStats[i].set_text(result);

        playerBoxes[i].add(playerStats[i]);
        playerBoxes[i].add(rageButtons[i]);
        scoresBox.pack_start(playerBoxes[i]);
        rageButtons[i].signal_clicked().connect(
                sigc::bind(
                    sigc::mem_fun(*this, &ScoreBoardView::onRageClicked), i));
    }
    disableRageQuit();
	scoresBox.show();
}

ScoreBoardView::~ScoreBoardView() {}

void ScoreBoardView::onRageClicked(int i) {
    Command humanCommand = Command();
    humanCommand.type = RAGEQUIT;
    mainWindow -> playerCommand(humanCommand);
}

void ScoreBoardView::updateView() {
    updateScores();
    disableRageQuit();
    enableRageQuit();
}

void ScoreBoardView::disableRageQuit() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        rageButtons[i].set_sensitive(false);
    }
}

void ScoreBoardView::enableRageQuit() {
    Player* currentPlayer = gamestate->getCurrentPlayer();
    if (currentPlayer->getPlayerType() == "h") {
        rageButtons[currentPlayer->getPlayerID()].set_sensitive(true);
    }
}

void ScoreBoardView::updateScores() {
	//update labels for each of the boxes
    vector<Player*> players = gamestate->getPlayersInGame();

    // upate the view
    for (int i = 0; i < players.size(); i++) {
        int currentScore = scoreboard->getCurrentScore(i);
        int numDiscards = players[i]->getNumDiscardedCards();
        string result = generateLabelMessage(i,currentScore,numDiscards);
        playerStats[i].set_text(result);
    }
}

string ScoreBoardView::generateLabelMessage(int playerID, int playerScore, int numDiscards) {
	string player ="\nPlayer ";
	string score = "\nScore: ";
	string discards = "\nDiscards: ";

	stringstream playerInfo;
	playerInfo << player << playerID+1 << score << playerScore << discards << numDiscards << endl;
	string result = playerInfo.str();
	return result;
}

// enable rage button if it is your turn
Gtk::HBox* ScoreBoardView::getScoreBox() {
	return &scoresBox;
}

void ScoreBoardView::setMainWindow(MainWindow* a) {
    mainWindow = a;
}
