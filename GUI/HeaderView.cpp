#include "HeaderView.h"
#include <iostream>
#include "mainwindow.h"
#include <string>

using namespace std;

HeaderView::HeaderView(): Component() {

	//initialize seed to 0
	//if no seed, default to using 0

	seed = 0;

	startButton.set_label("Start with seed:");
	endButton.set_label("Quit");

    startButton.signal_clicked().connect(
                sigc::mem_fun(*this, &HeaderView::onStartClicked));


	headerBox.add(startButton);
	headerBox.add(seedField);
	headerBox.add(endButton);
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
    mainWindow->startGame();
}
