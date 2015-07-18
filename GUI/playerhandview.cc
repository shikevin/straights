#include "playerhandview.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Sets the horizontal box to have homogeneous spacing (all elements are of the same size), and to put 10 pixels
// between each widget. Initializes the pixel buffer for the null place holder card, and the 10 of spades.
// Puts a frame in the window, and lays out the widgets horizontally. Four widgets are images, the fifth is a button
// with an image in it.
//
// Since widgets cannot be shared, must use pixel buffers to share images.
PlayerHandView::PlayerHandView(DeckGUI* deckPointer) : ViewComponent(), table( 1, 13, true ) {
    deckGUI = deckPointer;	
	const Glib::RefPtr<Gdk::Pixbuf> nullCardPixbuf = deckGUI->getNullCardImage();
	
	for (int i = 0; i < 13; i++ ) {
        nullCards[i] = new Gtk::Image( nullCardPixbuf );
        buttons[i].set_image( *nullCards[i] );
	} // for

    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            cards[suit][rank] = new Gtk::Image(deckGUI->getCardImage(Card((Suit)suit,(Rank)rank)));
        }
    }
	
	for (int i = 0; i < 13; i++) {
    buttons[i].signal_clicked().connect(
                sigc::bind(
									sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
									i));
      table.attach(buttons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
      //table.attach(object, left, right, top, bottom);
	buttons[i].show();
	}
	
}

PlayerHandView::~PlayerHandView() {
    for (int i = 0; i < 13; i++ ) delete nullCards[i];
    for (unsigned suit = CLUB; suit < SUIT_COUNT; ++suit) {
        for (unsigned rank = ACE; rank < RANK_COUNT; ++rank) {
            delete cards[suit][rank];
        }
    }
}

Gtk::Table* PlayerHandView::getViewBox() {
    return &table;
}

void PlayerHandView::onButtonClicked(int i) {
    buttons[i].hide();
}

void PlayerHandView::displayCards(Player* currentPlayer) {
    vector<Card*> playerCards = currentPlayer->getCardsInHand();
    for (int i = 0; i < playerCards.size(); i++) {
        cout << "Suit: " << playerCards[i]->getSuit() << " Rank: " << playerCards[i]->getRank() << endl;
        buttons[i].set_image(*cards[playerCards[i]->getSuit()][playerCards[i]->getRank()]);
    }
}
void PlayerHandView::updateView() {
    Player* currentPlayer = gamestate->getCurrentPlayer();
    if (currentPlayer->getPlayerType() == "h") {
        displayCards(currentPlayer);
    }
}
