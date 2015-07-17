#include "tableview.h"
#include <iostream>
#include <sstream>

using namespace std;

TableView::TableView(DeckGUI* deckPointer) : table( 4, 13, true ) {
    deck = deckPointer;	
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deck->getNullCardImage();
	
    for (unsigned suit = CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank = ACE; rank<= KING; ++rank) {
            card[suit][rank] = new Gtk::Image(deck->getCardImage(Card((Suit)suit,(Rank)rank)));
            buttons[suit][rank].set_image(*card[suit][rank]);
            // use the onButtonClicked as debug tool
            buttons[suit][rank].signal_clicked().connect(
                    sigc::bind(
                sigc::mem_fun( *this, &TableView::onButtonClicked ), suit, rank));
            table.attach(buttons[suit][rank], rank%13, (rank%13) + 1, suit%4, (suit%4) + 1);
            //table.attach(object, left, right, top, bottom);
            buttons[suit][rank].show();
        }
    }
}

TableView::~TableView() {
    // for int i = DeckGUI::card ... 
    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            delete card[suit][rank];
        }
    }
}

// debugging purposes
void TableView::onButtonClicked(unsigned suit, unsigned rank) {
    cout << "Suit: " << suit << "Rank: " << rank << endl;
}

Gtk::Table* TableView::getViewBox() {
    return &table;
}
