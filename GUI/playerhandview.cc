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
        cardsInHand[i] = new Gtk::Image( nullCardPixbuf );
        buttons[i].set_image( *cardsInHand[i] );
	} // for
	
	for (int i = 0; i < 13; i++) {
        buttons[i].signal_clicked().connect(
                    sigc::bind(
                                        sigc::mem_fun( *this, &PlayerHandView::onButtonClicked ),
                                        i));
          table.attach(buttons[i], i % 13, (i % 13) + 1, i / 13, (i / 13) + 1);
          //table.attach(object, left, right, top, bottom);
        buttons[i].set_sensitive(false);
        buttons[i].hide();
	}
	
}

PlayerHandView::~PlayerHandView() {
    for (int i = 0; i < 13; i++ ) delete cardsInHand[i];
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
    Gdk::Color red;
    Gdk::Color grey;
    grey.parse("grey");
    red.parse("red");
    for (int i = 0; i < 13; i++) {
    }
    for (int i = 0; i < playerCards.size(); i++) {
        if (gamestate->isFirstPlayer()) {
            if (*playerCards[i] == gamestate->startCard) {
                buttons[i].modify_bg(Gtk::StateType::STATE_NORMAL, red);
            } else {
                buttons[i].modify_bg(Gtk::StateType::STATE_NORMAL, grey);
            }
        } else if (deck->isCardPlayable(*playerCards[i])) {
            buttons[i].modify_bg(Gtk::StateType::STATE_NORMAL, red);
        } else {
            buttons[i].modify_bg(Gtk::StateType::STATE_NORMAL, grey);
        }
        cardsInHand[i]->set(deckGUI->getCardImage(Card((Suit)playerCards[i]->getSuit(),(Rank)playerCards[i]->getRank())));
    }

    for (int i = 0; i < 13; i++) {
        buttons[i].set_sensitive(true);
        if (i < playerCards.size()) {
            buttons[i].show();
        } else {
            buttons[i].hide();
        }
    }
}
void PlayerHandView::updateView() {
    Player* currentPlayer = gamestate->getCurrentPlayer();
    displayCards(currentPlayer);
}

void PlayerHandView::setMainWindow(MainWindow* a) {
    mainWindow = a;
}
