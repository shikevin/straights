#ifndef SCOREBOADVIEW_H
#define SCOREBOADVIEW_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include "component.h"
#include "mainwindow.h"

class MainWindow;

class ScoreBoardView : public ViewComponent {
public:
	ScoreBoardView();
	virtual ~ScoreBoardView();
    Gtk::HBox* getScoreBox();
    void updateView();
    void setMainWindow(MainWindow*);
	
private:
	static const int NUM_PLAYERS = 4;
	std::string generateLabelMessage( int , int , int );
    void updateScores();
    void enableRageQuit();
    void disableRageQuit();
    void onRageClicked(int);
	// Member widgets:
	Gtk::Button rageButtons[4];      		// buttons responsible for raging
	Gtk::Label playerStats[NUM_PLAYERS];
	Gtk::VBox playerBoxes[NUM_PLAYERS];
	Gtk::HBox scoresBox;             // Horizontal box for aligning player button's boxes.
    MainWindow* mainWindow;
};

#endif
