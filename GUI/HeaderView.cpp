#include "HeaderView.h"
#include <iostream>
#include "mainwindow.h"
#include <string>
#include <exception>
#include <gtkmm/dialog.h>

using namespace std;

HeaderView::HeaderView(): ViewComponent() {

	//initialize seed to 0
	//if no seed, default to using 0

	seed = 0;

	startButton.set_label("Start with seed:");
	endButton.set_label("Quit");

    startButton.signal_clicked().connect(
                sigc::mem_fun(*this, &HeaderView::onStartClicked));

    endButton.signal_clicked().connect(
                sigc::mem_fun(*this, &HeaderView::onEndClicked));


	headerBox.add(startButton);
	headerBox.add(seedField);
	headerBox.add(endButton);
	seedField.set_text("0");
	seedField.show();
	headerBox.show();

}

HeaderView::~HeaderView() {}

void HeaderView::setMainWindow(MainWindow* window) {
    mainWindow = window;
}

void HeaderView::updateView() {
}

Gtk::HBox* HeaderView::getHeaderView() {
	return &headerBox;
}

void HeaderView::onStartClicked() {
	string potentialSeed = seedField.get_text();
	try {
		seed = stoi (potentialSeed);
		cout << seed << endl;
	}
	catch(...) {
		cerr << "NIGGA WHY YOU DO DIS" << endl;
		Gtk::Dialog dialogBox("NIGGA WHY YOU DO DIS", false);
		dialogBox.set_default_size(350,200);
		dialogBox.run();
		return;
	}

	seedField.set_text(to_string(seed));
    mainWindow->startGame(seed);
}

void HeaderView::onEndClicked() {
	exit(0);
}


