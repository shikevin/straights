#include "playerselectiondialog.h"
#include <gtkmm/stock.h>
#include <gtkmm/window.h>
#include <iostream>

using namespace std;
// Specifies the parent window of the dialog box and the title of the dialog box.
PlayerSelectionDialog::PlayerSelectionDialog( Gtk::Window & parentWindow, string title) : Dialog( title, parentWindow, true, true ) {
    cout << "fail 2" << endl;
	vector<string> messages;
	messages.push_back( "Human" );
	messages.push_back( "Computer" );
	
	// Obtain the dialog box's vertical alignment box.
	Gtk::VBox* contentArea = this->get_vbox();
    cout << "fail 3" << endl;
	
	// Set up a group of radio buttons, one per card in human player's hand plus the top card of the kitty.
	for ( int i = 0; i < messages.size(); i++ ) {
		buttons.push_back( Gtk::manage( new Gtk::RadioButton( group, messages[i] ) ) );
		contentArea->add( *buttons[i] );
	} // for
    cout << "fail 4" << endl;
	
	// Make the first button the initial active choice.
	buttons[0]->set_active();
	
	// Add a standard "ok" buttons with the appropriate responses when clicked.
    Gtk::Button * okButton = add_button( Gtk::Stock::OK, Gtk::RESPONSE_OK);
    cout << "fail 5" << endl;
    set_default_size(300,150);
	show_all_children();
	
} // PlayerSelectionDialog:PlayerSelectionDialog:

char PlayerSelectionDialog::getChoice() {
    cout << "hasn't failed in getChoice" << endl;
    // Wait for a response from the dialog box.
	int result = run();
    cout << "hasn't failed in getChoice1" << endl;
    switch (result) {
        case Gtk::RESPONSE_OK:
            if (buttons[0]->get_active()) {
                return 'h';
            } else {
                return 'c';
            }
            break;
        default:
            return 'n';
    } // switch    	
}

PlayerSelectionDialog::~PlayerSelectionDialog() {
	for ( int i = 0; i < buttons.size(); i++ ) delete buttons[i];
	buttons.clear();
} // PlayerSelectionDialog::PlayerSelectionDialog~
