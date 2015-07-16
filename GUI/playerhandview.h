#ifndef __PLAYER_HAND_VIEW_H
#define __PLAYER_HAND_VIEW_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>

#include "DeckGUI.h"

class PlayerHandView {
public:
	PlayerHandView();
	virtual ~PlayerHandView();
    Gtk::HBox* getViewBox();
	
private:
	DeckGUI                         deck;             // Knows all of the card pixel buffers.
	
	// Member widgets:
	Gtk::Image                    * card[13];          // Images to display.
	Gtk::Button                     button;           // Button that will hold an image.
	Gtk::HBox                       hbox;             // Horizontal box for aligning widgets in the window.
};

#endif
