#ifndef SCOREBOADVIEW_H
#define SCOREBOADVIEW_H
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include "component.h"


class ScoreBoardView : public ViewComponent {
public:
	ScoreBoardView();
	virtual ~ScoreBoardView();
    Gtk::HBox* getScoreBox();
    void updateView();
	
private:
	int currPlayerID;             // store id of current player			
	
	// Member widgets:
	Gtk::Button rageButtons[4];      		// buttons responsible for raging

	Gtk::Label player1Label;
	Gtk::Label player2Label;
	Gtk::Label player3Label;
	Gtk::Label player4Label;


	Gtk::VBox player1Box;
	Gtk::VBox player2Box;
	Gtk::VBox player3Box;
	Gtk::VBox player4Box;


	Gtk::HBox scoresBox;             // Horizontal box for aligning player button's boxes.

};

#endif
