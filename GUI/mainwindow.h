#ifndef __MAIN_WINDOW_H
#define __MAIN_WINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

#include "DeckGUI.h"

class MainWindow : public Gtk::Window {
public:
	MainWindow();
	virtual ~MainWindow();
	
private:
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
	// Member widgets:
	Gtk::Image                    * card[13];          // Images to display.
	Gtk::Button                     button;           // Button that will hold an image.
	Gtk::HBox                       hbox;             // Horizontal box for aligning widgets in the window.
	Gtk::Frame                      frame;            // Create a nice framed border for the box.
};

#endif
