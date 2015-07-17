#ifndef __PLAYER_SELECTION_BOX_H
#define __PLAYER_SELECTION_BOX_H
#include <gtkmm/dialog.h>
#include <gtkmm/box.h>
#include <gtkmm/radiobuttongroup.h>
#include <gtkmm/radiobutton.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

class PlayerSelectionDialog : Gtk::Dialog {
public:
	// Specifies the parent window of the dialog box and the title of the dialog box.
	PlayerSelectionDialog( Gtk::Window & parentWindow, string title);
	virtual ~PlayerSelectionDialog();
    char getChoice();
	
private:
	Gtk::RadioButton::Group      group;          // Used to group the radio buttons so only one can be active at a time.
	vector<Gtk::RadioButton *>   buttons;        // Buttons for the messages.
}; //PlayerSelectionDialog 
#endif
