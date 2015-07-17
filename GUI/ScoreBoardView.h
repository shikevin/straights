#ifndef SCOREBOADVIEW_H
#define SCOREBOADVIEW_H
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>


class ScoreBoardView {
public:
	ScoreBoardView();
	virtual ~ScoreBoardView();
    Gtk::HBox* getScoreBox();
	
private:
	int currScores[4];             // keep track of player scores? or can just ask for it
	int numDiscards[4];				
	
	// Member widgets:
	Gtk::Button rageButtons[4];      		// buttons responsible for raging

	Gtk::Label player1Label;
	//Gtk::Label player2Label;
	//Gtk::Label player3Label;
	//Gtk::Label player4Label;


	Gtk::VBox player1Box;
	Gtk::VBox player2Box;
	Gtk::VBox player3Box;
	Gtk::VBox player4Box;

	//Gtk::VBox player1subBox;
	//Gtk::VBox player2subBox;
	//Gtk::VBox player3subBox;
	//Gtk::VBox player4subBox;

	Gtk::HBox scoresBox;             // Horizontal box for aligning widgets in the window.

};

#endif
