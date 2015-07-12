#include "mainwindow.h"

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
MainWindow::MainWindow() : hbox( true, 10 ) {
		
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck.getNullCardImage();
	const Glib::RefPtr<Gdk::Pixbuf> cardPixbuf     = deck.getCardImage( TEN, SPADE );
	
	// Sets the border width of the window.
	set_border_width( 10 );
		
	// Set the look of the frame.
	frame.set_label( "Cards:" );
	frame.set_label_align( Gtk::ALIGN_CENTER, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
	
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );
	
	// Add the horizontal box for laying out the images to the frame.
	frame.add( hbox );
	
	// Initialize 4 empty cards and place them in the box.
	for (int i = 0; i < 12; i++ ) {
		card[i] = new Gtk::Image( nullCardPixbuf );
		hbox.add( *card[i] );
	} // for
	
	// Initialize the 5th card and place the image into the button.
	card[12] = new Gtk::Image( cardPixbuf );	
	button.set_image( *card[12] );	
			
	// Add the button to the box.
	hbox.add( button );
	
	// The final step is to display this newly created widget.
	show_all();
}

MainWindow::~MainWindow() {
	for (int i = 0; i < 13; i++ ) delete card[i];
}
