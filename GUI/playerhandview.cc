#include "playerhandview.h"
#include <iostream>

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
PlayerHandView::PlayerHandView() : hbox( true, 10 ) {
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( TEN, SPADE );
	
    
	// Initialize 12 empty cards and place them in the box.
	for (int i = 0; i < 12; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hbox.add( *card[i] );
	} // for
	
	// Initialize the 5th card and place the image into the button.
	card[12] = new Gtk::Image( cardPixbuf );	
	button.set_image( *card[12] );	
    button.signal_clicked().connect(
                sigc::bind(
									sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
									0));
	button.show();
			
	// Add the button to the box.
	hbox.add( button );
}

PlayerHandView::~PlayerHandView() {
	for (int i = 0; i < 13; i++ ) delete card[i];
}

Gtk::HBox* PlayerHandView::getViewBox() {
    return &hbox;
}

void PlayerHandView::onButtonClicked(int i) {
    cout << "button click event";
    button.hide();
}
