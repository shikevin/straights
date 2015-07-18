#include "playerhandview.h"
#include <iostream>
#include "Command.h"
#include <string>
#include <sstream>

using namespace std;

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
	buttons[i].hide();
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
    if (gamestate->getCurrentPlayer()->getPlayerType() == "h") {
        vector<Card*> playerCards = gamestate->getCurrentPlayer()->getCardsInHand();
        Command humanCommand = Command();
        humanCommand.type = PLAY;
        humanCommand.card = *playerCards[i];
        mainWindow -> playerCommand(humanCommand);
    }
}

void PlayerHandView::displayCards(Player* currentPlayer) {
    vector<Card*> playerCards = currentPlayer->getCardsInHand();
    for (int i = 0; i < 13; i++) {
        if (i < playerCards.size()) {
            buttons[i].set_image(*cards[playerCards[i]->getSuit()][playerCards[i]->getRank()]);
            buttons[i].show();
        } else {
            buttons[i].hide();
        }
    }
}
void PlayerHandView::updateView() {
    Player* currentPlayer = gamestate->getCurrentPlayer();
    if (currentPlayer->getPlayerType() == "h") {
        displayCards(currentPlayer);
    }
}

void PlayerHandView::setMainWindow(MainWindow* a) {
    mainWindow = a;
}
