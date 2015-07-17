#ifndef SCOREBOADVIEW_H
#define SCOREBOADVIEW_H
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>


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
	Gtk::Label player2Label;
	Gtk::Label player3Label;
	Gtk::Label player4Label;


	Gtk::HBox player1Box;
	Gtk::HBox player2Box;
	Gtk::HBox player3Box;
	Gtk::HBox player4Box;

	Gtk::HBox scoresBox;             // Horizontal box for aligning widgets in the window.

};

#endif
