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
#include "mainwindow.h"

class MainWindow;

class HeaderView : public ViewComponent {
public:
	HeaderView();
    virtual ~HeaderView();
    Gtk::HBox* getHeaderView();
    void updateView();
    void setMainWindow(MainWindow*);
	
private:
    void onStartClicked();
    void onEndClicked();
	int seed;             // store inputed seed		
	
	// Member widgets:
	Gtk::Button startButton;
	Gtk::Button endButton;
	Gtk::Entry seedField;
	Gtk::HBox headerBox;

    MainWindow* mainWindow;
};

#endif
