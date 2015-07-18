#ifndef __PLAYER_HAND_VIEW_H
#define __PLAYER_HAND_VIEW_H
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/table.h>
#include "Player.h"
#include "Card.h"

#include "component.h"
#include "mainwindow.h"
#include "DeckGUI.h"

class MainWindow;
class PlayerHandView : public ViewComponent {
public:
	PlayerHandView(DeckGUI*);
	~PlayerHandView();
    Gtk::Table* getViewBox();
    void updateView();
    void setMainWindow(MainWindow*);
	
private:
    void onButtonClicked(int);
    void displayCards(Player*);
	DeckGUI*                         deckGUI;             // Knows all of the card pixel buffers.
    	
	// Member widgets:
    Gtk::Image * cards[SUIT_COUNT][RANK_COUNT];          // Images to display.
	Gtk::Button buttons[13];
    Gtk::Image * nullCards[13];
	Gtk::Table                       table;             // Horizontal box for aligning widgets in the window.


    // Should be done in component but it seems to be segfaulting...
    MainWindow* mainWindow;
};

#endif
