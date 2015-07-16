#include "hidebuttons.h"
#include <iostream>
#include <gtkmm/stock.h>
#include <string>
#include <cstdlib>
#include <sstream>
HideButtons::HideButtons() : table(1, 10, true) { 
	// 10 rows, 10 columns, "true" is for "homogeneous" - whether or not all the
	// table cells are the same width/height.
	for (int i = 0; i < 10; i++) {
		std::ostringstream ss;
		ss << "I am " << i;
		buttons[i].set_label(ss.str());
	}
        
	// Sets the border width of the window.
	set_border_width( 0 );
	set_default_size(500, 50);
    
	add( table );
	
	for (int i = 0; i < 10; i++) {
    buttons[i].signal_clicked().connect(
                sigc::bind(
									sigc::mem_fun( *this, &HideButtons::onButtonClicked ),
									i));
      table.attach(buttons[i], i % 10, (i % 10) + 1, i / 10, (i / 10) + 1);
	buttons[i].show();
	}
	
	table.show();
}

HideButtons::~HideButtons() {}

void HideButtons::onButtonClicked(int i) {
	std::cout << "You clicked: " << i << std::endl;
	buttons[i].hide();
}

