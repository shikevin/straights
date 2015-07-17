#include "mainwindow.h"
#include <iostream>
#include <gtkmm/box.h>
#include "Card.h"
#include <gtkmm/table.h>
#include "playerselectiondialog.h"

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
MainWindow::MainWindow() {
    tableView = new TableView(&deck);
    handView = new PlayerHandView(&deck);
		
	// Sets the border width of the window.
	set_border_width( 25 );
		
	// Set the look of the frame.
	frame.set_label_align( Gtk::ALIGN_LEFT, Gtk::ALIGN_TOP );
	frame.set_shadow_type( Gtk::SHADOW_ETCHED_OUT );
    
   
	// Add the frame to the window. Windows can only hold one widget, same for frames.
	add( frame );

	mainBox.pack_start(*headerView.getHeaderView());
    mainBox.pack_start(*tableView->getViewBox());
	mainBox.pack_start(*scoreView.getScoreBox());
	mainBox.pack_start(*handView->getViewBox());

	// Add the horizontal box for laying out the images to the frame.
	frame.add(mainBox);

	// The final step is to display this newly created widget.
	show_all();

    startGame();
}

void MainWindow::startGame() {
    string choices = invitePlayers();
    gameLogic = new Table(0);
    gameLogic.playGame(choices);
}

string MainWindow::invitePlayers() {
    string choices = "";
    for (int i = 0; i < 4; i++) {
        string title = "Choose Type: Player " + to_string(i + 1);
        char type;
        do {
            PlayerSelectionDialog selection(*this, title);
            type = selection.getChoice();
        } while (type == 'n');
        cout << "Type for : " << i << " is "<< type << endl;
        choices += type;
    }
    return choices;
}

MainWindow::~MainWindow() {
}
