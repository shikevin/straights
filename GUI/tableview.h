#ifndef __TABLE_VIEW_H
#define __TABLE_VIEW_H
#include <gtkmm/image.h>
#include <gtkmm/table.h>
#include <gtkmm/button.h>
#include "Card.h"
#include "DeckGUI.h"

class TableView {
public:
	TableView(DeckGUI*);
	~TableView();
    Gtk::Table* getViewBox();
    void onButtonClicked(unsigned, unsigned);
    // void clearTable();
    // void showCard();
	
private:
    DeckGUI* deck;
	// Member widgets:
    Gtk::Image * card[SUIT_COUNT][RANK_COUNT];          // Images to display.
	Gtk::Button buttons[SUIT_COUNT][RANK_COUNT];
	Gtk::Table                       table;             // Horizontal box for aligning widgets in the window.
};

#endif
