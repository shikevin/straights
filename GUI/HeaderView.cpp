#include "HeaderView.h"
#include <string>

HeaderView::HeaderView() {

	//initialize seed to 0
	//if no seed, default to using 0

	seed = 0;

	startButton.set_label("Start with seed:");
	endButton.set_label("Quit");


	headerBox.add(startButton);
	headerBox.add(seedField);
	headerBox.add(endButton);
	seedField.show();
	headerBox.show();

}

HeaderView::~HeaderView() {}




Gtk::HBox* HeaderView::getHeaderView() {
	return &headerBox;
}