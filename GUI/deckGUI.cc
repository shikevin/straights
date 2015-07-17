#include "DeckGUI.h"
#include <algorithm>
#include <iterator>
#include <string>
#include "Card.h"
#include <iostream>
using std::string;
using std::transform;

using namespace std;

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const string & name) {
	return Gdk::Pixbuf::create_from_file( name );
} // createPixbuf

DeckGUI::DeckGUI()  {
    for (unsigned suit = CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank = ACE; rank<= KING; ++rank) {
            string filename = "cards_png/" + to_string(suit) + "_" + to_string(rank) + ".png";
            image_names[suit][rank] = filename.c_str();
            cout << image_names[suit][rank] << endl;
            deck.push_back(createPixbuf(image_names[suit][rank]));
        }
    }
	// Images can only be loaded once the main window has been initialized, so cannot be done as a static
	// constant array. Instead, use the STL transform algorithm to apply the method createPixbuf to every
	// element in the array of image names, starting with first and ending with the last. New elements are
	// added to the back of deck.
    // jfor (unsigned suit = CLUB; suit <= SPADE; ++suit) {
    //     transform( &image_names[suit][ACE], &image_names[suit][KING], 
    //                std::back_inserter(deck), &createPixbuf );
    // }
    deck.push_back(createPixbuf("cards_png/nothing.png"));
} // DeckGUI::DeckGUI

DeckGUI::~DeckGUI() {
} // DeckGUI::~DeckGUI

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::getCardImage( Card card ) {
	int index = ((int) card.getSuit())*4 + ((int) card.getRank() );
	return deck[ index ];
} // DeckGUI::getCardImage 

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::getNullCardImage() {
	int size = deck.size();
	return deck[ size-1 ];
} // DeckGUI::getNullCardImage
