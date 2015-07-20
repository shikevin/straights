#include "mainwindow.h"
#include <iostream>
#include <gtkmm/box.h>
#include "Card.h"
#include <gtkmm/table.h>
#include "validate.h"

using namespace std;

MainWindow::MainWindow() {
    tableView = new TableView(&deck);
    handView = new PlayerHandView(&deck);
    headerView = new HeaderView();
    scoreView = new ScoreBoardView();
    engine = irrklang::createIrrKlangDevice();
    engine->play2D("music.mp3", true);
    gameLogic = NULL;
		
	// Sets the border width of the window.
	set_border_width( 25 );
		
	// Set the look of the frame.
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    
   
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );

	mainBox.pack_start(*headerView->getHeaderView());
    mainBox.pack_start(*tableView->getViewBox());
	mainBox.pack_start(*scoreView->getScoreBox());
	mainBox.pack_start(*handView->getViewBox());

    components.push_back(dynamic_cast<ViewComponent*>(tableView));
    components.push_back(dynamic_cast<ViewComponent*>(scoreView));
    components.push_back(dynamic_cast<ViewComponent*>(handView));

	// Add the horizontal box for laying out the images to the frame.
	frame.add(mainBox);

	// The final step is to display this newly created widget.
	show_all();

    // THIS SHOULD WORK BUT IS SEGFAULTING
    // for (int i = 0; i < components.size(); i++) {
    //     components[i]->setMainWindow(this);
    // }
    tableView->setMainWindow(this);
    handView->setMainWindow(this);
    headerView->setMainWindow(this);
    scoreView->setMainWindow(this);
}

MainWindow::~MainWindow() {
    engine->drop();
    delete tableView;
    delete handView;
    delete headerView;
}

void MainWindow::startGame(int seed) {
    string choices = invitePlayers();
    if (gameLogic == NULL) {
        gameLogic = new TableController(components, this);
    }
    gameLogic->playGame(seed, choices);
}

string MainWindow::invitePlayers() {
    string choices = "";
    for (int i = 0; i < 4; i++) {
        string title = "Choose Type: Player " + to_string(i + 1);
        char type;
        do {
            PlayerSelectionDialog selection(*this, title);
            type = selection.getChoice();
        } while (type == 'n');
        choices += type;
    }
    return choices;
}

void MainWindow::playerCommand(Command command) {
    try {
        gameLogic->playerCommand(command);
    } catch (Validate::PlayerQuitException &e) {
        // handle quit
    } catch (Validate::LegalPlayExistsException &e) {
        // tell user to use the right card
    	displayDialog();
		return;
    } catch (Validate::IllegalPlayException &e) {
        command.type = DISCARD;
        playerCommand(command);
    } catch (Validate::PrintDeckException &e) {
    }
}

void MainWindow::displayDialog() {
	generateDialog("ILLEGAL PLAY", "Legal Play Exists.\n\nAnd its not that one.",250,300);
}

void MainWindow::setGameState(GameState* a){
    gamestate = a;
}

void MainWindow::setScoreboard(Scoreboard* a){
    scoreboard = a;
}

void MainWindow::gameOver() {
    //information->printWinner(scoreboard->getLowestID());
    vector<int> winners = scoreboard->getLowestID();
    for(int i = 0; i < winners.size(); i++) {
    	string message;
    	if(winners.size() == 1) {
    		message = "Player "+ to_string(winners[i] + 1) + " wins!";
    	} else { 
    		message = "Player "+ to_string(winners[i] + 1) + " is a winner!";
    	}
    	generateDialog("GAME OVER!", message, 300,200);
    }

}

void MainWindow::roundOver() {
    //information->printPlayerResults(i, scoreboard->getOldScore(i), scoreboard->getCurrentScore(i), playersInGame[i]->getDiscardedCards());
	vector<Player*> playersInGame = gamestate->getPlayersInGame();
	int playerName;
	int numDiscards;
	vector<Card*> discards;
	int totalScore;
	int roundScore;

	string displayText= "\tROUND SUMMARY\n\n";

	for(int i = 0; i < playersInGame.size(); i++) {
		playerName = i+1;
		numDiscards = playersInGame[i]->getNumDiscardedCards();
		roundScore = scoreboard->getCurrentScore(i);
		totalScore = scoreboard->getOldScore(i) + roundScore;
		discards = playersInGame[i]->getDiscardedCards();

		displayText += generateRoundOverMessage(playerName, numDiscards, discards, totalScore, roundScore);
	}

	generateRoundOverDialog(displayText);	
}

void MainWindow::generateDialog(string title, string info, int width, int height) {
	Gtk::Dialog dialogBox(title, *this, true, true);
		dialogBox.set_default_size(width,height);
		Gtk::Label message(info);
		dialogBox.get_vbox()->add(message);
		dialogBox.add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
		//dialogBox.add_button(Gtk::Stock::OK);
		dialogBox.show_all();
		dialogBox.run();
}

void MainWindow::generateRoundOverDialog(string displayText) {
		generateDialog("ROUND OVER!",displayText,400,400);
}

string MainWindow::generateRoundOverMessage(int playerName, int numDiscards, vector<Card*> discards, int totalScore, int roundScore) {
	string message = "\n\n";
	message += "Player " + to_string(playerName) + ":\n";
	message += "Round Score: " + to_string(roundScore) + "\n";
	message += "Number of Discards: " + to_string(numDiscards) + "\n";
	string discardedCards = getDiscardedCardsAsString(discards);
	message += "Cards Discarded: " + discardedCards + "\n\n";
	message += "Total Score: " + to_string(totalScore);
	return message;
}

string MainWindow::getDiscardedCardsAsString(vector<Card*> discards) {
	string result = "";
	for(int i = 0; i < discards.size(); i++) {
		stringstream cardString;
		cardString << *discards[i];
		result +=  cardString.str() +  " ";
		cout << result << endl;
	}
	return result;
}
