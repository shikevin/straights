#ifndef _HIDEBUTTONS_H
#define _HIDEBUTTONS_H
#include <string>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/table.h>
#include <gtkmm/window.h>

class HideButtons : public Gtk::Window {
public:
	HideButtons();
	virtual ~HideButtons();
	
protected:
	// Signal handlers:
	virtual void onButtonClicked(int);
	
	// Member widgets:
	Gtk::Button buttons[10];

	Gtk::Table table;
	
	int index;
};

#endif
