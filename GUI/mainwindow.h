#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/frame.h>
#include "playerhandview.h"
#include "tableview.h"
#include "ScoreBoardView.h"
#include "HeaderView.h"
#include "TableController.h"
#include "playerselectiondialog.h"

class HeaderView;

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	~MainWindow();
    void startGame();
    // newRound();
    // newGame();
	
private:
    string invitePlayers();
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
    TableController* gameLogic;
    TableView*                      tableView;
    PlayerHandView*                 handView;
    ScoreBoardView					scoreView;
    HeaderView*						headerView;
	Gtk::Frame                      frame; 
	Gtk::VBox           			mainBox;
};

#endif
