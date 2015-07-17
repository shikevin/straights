#include "playerhandview.h"
#include <iostream>
#include <sstream>

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
PlayerHandView::PlayerHandView() : table( 1, 13, true ) {
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( TEN, SPADE );
	
    
	// for (int i = 0; i < 10; i++) {
	// 	std::ostringstream ss;
	// 	ss << "I am " << i;
	// 	buttons[i].set_label(ss.str());
	// }
	// Initialize 12 empty cards and place them in the box.
	for (int i = 0; i < 12; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
        buttons[i].set_image( *card[i] );
	} // for
	
	// Initialize the 5th card and place the image into the button.
	card[12] = new Gtk::Image( cardPixbuf );	
	buttons[12].set_image( *card[12] );	
    // buttons[12].signal_clicked().connect(
    //             sigc::bind(
	// 								sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
	// 								0));
    // //table.attach(button[12], 12 % 13, (12 % 13) + 1, 12 / 13, (12 / 13) + 1);
	// buttons[12].show();

	for (int i = 0; i < 13; i++) {
    buttons[i].signal_clicked().connect(
                sigc::bind(
									sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
									i));
      table.attach(buttons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
	buttons[i].show();
	}
	
}

PlayerHandView::~PlayerHandView() {
    for (int i = 0; i < 13; i++ ) delete card[i];
}

Gtk::Table* PlayerHandView::getViewBox() {
    return &table;
}

void PlayerHandView::onButtonClicked(int i) {
    cout << "button click event";
    buttons[i].hide();
}
