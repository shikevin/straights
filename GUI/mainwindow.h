#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/frame.h>
#include "playerhandview.h"

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	virtual ~MainWindow();
	
private:
    PlayerHandView                  handView;
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
};

#endif
