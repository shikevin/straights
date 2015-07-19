#include "tableview.h"
#include <iostream>
#include <sstream>

using namespace std;

TableView::TableView(DeckGUI* deckPointer) : ViewComponent(), table( 4, 13, true ) {
    deckGUI = deckPointer;	

    for (unsigned suit = CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank = ACE; rank<= KING; ++rank) {
            nullCards[suit][rank] = new Gtk::Image(deckGUI->getNullCardImage());
            card[suit][rank] = new Gtk::Image(deckGUI->getCardImage(Card((Suit)suit,(Rank)rank)));
            // use the onButtonClicked as debug tool
            buttons[suit][rank].set_image(*nullCards[suit][rank]);
            buttons[suit][rank].signal_clicked().connect(
                    sigc::bind(
                sigc::mem_fun( *this, &TableView::onButtonClicked ), suit, rank));
            table.attach(buttons[suit][rank], rank%13, (rank%13) + 1, suit%4, (suit%4) + 1);
            //table.attach(object, left, right, top, bottom);
            buttons[suit][rank].set_sensitive(false);
        }
    }
}

TableView::~TableView() {
    // for int i = DeckGUI::card ... 
    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            delete card[suit][rank];
            delete nullCards[suit][rank];
        }
    }
}

void TableView::clearTable() {
    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            buttons[suit][rank].set_image(*nullCards[suit][rank]);
        }
    }
}

void TableView::showCard(Card show) {
    unsigned rank = show.getRank();
    unsigned suit = show.getSuit();
    buttons[suit][rank].set_image(*card[suit][rank]);
}

// debugging purposes
void TableView::onButtonClicked(unsigned suit, unsigned rank) {
    cout << "Suit: " << suit << "Rank: " << rank << endl;
}

Gtk::Table* TableView::getViewBox() {
    return &table;
}

void TableView::updateView() {
    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            if (deck->isCardOnTable(Card((Suit)suit,(Rank)rank))) {
                buttons[suit][rank].set_image(*card[suit][rank]);
            } else {
                buttons[suit][rank].set_image(*nullCards[suit][rank]);
            }
        }
    }
}

void TableView::setMainWindow(MainWindow* a) {
    mainWindow = a;
}
