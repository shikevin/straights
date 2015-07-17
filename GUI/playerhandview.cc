#include "playerhandview.h"
#include <iostream>
#include <string>
#include "Card.h"
#include <sstream>

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
PlayerHandView::PlayerHandView(DeckGUI* deckPointer) : Component(), table( 1, 13, true ) {
    deck = deckPointer;	
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck->getNullCardImage();
	
	for (int i = 0; i < 13; i++ ) {
        nullCards[i] = new Gtk::Image( nullCardPixbuf );
		cards[i] = new Gtk::Image( nullCardPixbuf );
        buttons[i].set_image( *cards[i] );
	} // for
	
	for (int i = 0; i < 13; i++) {
    buttons[i].signal_clicked().connect(
                sigc::bind(
									sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
									i));
      table.attach(buttons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
      //table.attach(object, left, right, top, bottom);
	buttons[i].show();
	}
	
}

PlayerHandView::~PlayerHandView() {
    for (int i = 0; i < 13; i++ ) delete cards[i];
}

Gtk::Table* PlayerHandView::getViewBox() {
    return &table;
}

void PlayerHandView::onButtonClicked(int i) {
    buttons[i].hide();
}

void PlayerHandView::updateView() {
}
