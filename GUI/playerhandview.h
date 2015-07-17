#ifndef __PLAYER_HAND_VIEW_H
#define __PLAYER_HAND_VIEW_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/table.h>

#include "component.h"
#include "DeckGUI.h"

class PlayerHandView : public Component {
public:
	PlayerHandView(DeckGUI*);
	~PlayerHandView();
    Gtk::Table* getViewBox();
    void onButtonClicked(int);
    void updateView();
	
private:
	DeckGUI*                         deck;             // Knows all of the card pixel buffers.
    	
	// Member widgets:
    Gtk::Image                    * cards[13];          // Images to display.
	Gtk::Button buttons[13];
	Gtk::Table                       table;             // Horizontal box for aligning widgets in the window.
};

#endif
