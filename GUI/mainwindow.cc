#include "mainwindow.h"
#include <gtkmm/box.h>

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
MainWindow::MainWindow() {
		
	// Sets the border width of the window.
	set_border_width( 20 );
		
	// Set the look of the frame.
	frame.set_label( "Your Hand" );
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    
   
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );
	
	// Add the horizontal box for laying out the images to the frame.
	frame.add(*handView.getViewBox());
	
	// The final step is to display this newly created widget.
	show_all();
}

MainWindow::~MainWindow() {
}
