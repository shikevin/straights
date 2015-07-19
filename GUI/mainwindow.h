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
#include "component.h"

class PlayerHandView;
class HeaderView;
class TableView;
class ScoreBoardView;

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	~MainWindow();
    void startGame(int);
    void playerCommand(Command);
    // newRound();
    // newGame();
	
private:
    string invitePlayers();
    void displayDialog();
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
    std::vector<ViewComponent*> components;
	
    TableController* gameLogic;
    TableView*                      tableView;
    PlayerHandView*                 handView;
    ScoreBoardView*					scoreView;
    HeaderView*						headerView;
	Gtk::Frame                      frame; 
	Gtk::VBox           			mainBox;
};

#endif
