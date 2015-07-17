#ifndef HEADERVIEW_H
#define HEADERVIEW_H
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/image.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>
#include <gtkmm/dialog.h>
#include <gtkmm/stock.h>
#include <gtkmm/entry.h>


class HeaderView {
public:
	HeaderView();
	virtual ~HeaderView();
    Gtk::HBox* getHeaderView();
	
private:
	int seed;             // store inputed seed		
	
	// Member widgets:
	Gtk::Button startButton;
	Gtk::Button endButton;
	Gtk::Entry seedField;
	Gtk::HBox headerBox;

};

#endif
