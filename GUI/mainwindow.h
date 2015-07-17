#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/frame.h>
#include "playerhandview.h"
#include "ScoreBoardView.h"

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	~MainWindow();
	
private:
    PlayerHandView                  handView;
    ScoreBoardView					scoreView;
	Gtk::Frame                      frame; 
	Gtk::VBox           			mainBox;

};

#endif
