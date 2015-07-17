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
            deck.push_back(createPixbuf(image_names[suit][rank]));
        }
    }
    deck.push_back(createPixbuf("cards_png/nothing.png"));
} // DeckGUI::DeckGUI

DeckGUI::~DeckGUI() {
} // DeckGUI::~DeckGUI

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::getCardImage( Card card ) {
	int index = card.getSuit()*13 + card.getRank();
	return deck[ index ];
} // DeckGUI::getCardImage 

// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::getNullCardImage() {
	int size = deck.size();
	return deck[ size-1 ];
} // DeckGUI::getNullCardImage
