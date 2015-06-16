#include "Deck.h"
#include "Card.h"
#include <string>
#include <assert.h>
using namespace std;

// This will zero initiate the scores
Deck::Deck() {
    Card* newCard;
    int i = 0;
    for (unsigned suit=CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank=ACE; rank <= KING; ++rank) {
            newCard = new Card(Suit(suit), Rank(rank));
            allCards_[i] = newCard;
            onTable_[suit][rank] = NULL;
            i++;
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i<CARDS_IN_DECK ; i++) {
        delete allCards_[i];
    }
}

void Deck::newRound() {
    for (unsigned suit=CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank=ACE; rank<= KING; ++rank) {
            onTable_[suit][rank] = NULL;
        }
    }
}

void Deck::play(Card *card) {
    assert(card!=NULL);
    onTable_[card->getSuit()][card->getRank()] = card; 
}
