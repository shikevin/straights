#ifndef SCOREBOADVIEW_H
#define SCOREBOADVIEW_H
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
	static const int NUM_PLAYERS = 4;
	int currPlayerID;             // store id of current player			
	
	// Member widgets:
	Gtk::Button rageButtons[4];      		// buttons responsible for raging

	Gtk::Label playerStats[NUM_PLAYERS];
	Gtk::VBox playerBoxes[NUM_PLAYERS];
	Gtk::HBox scoresBox;             // Horizontal box for aligning player button's boxes.

	std::string generateLabelMessage( int , int , int );

};

#endif
