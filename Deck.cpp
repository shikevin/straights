#include "Deck.h"
#include "Card.h"
#include <string>
#include <assert.h>
#include <random>
using namespace std;

// This will zero initiate the scores
static Card*::latestCard = NULL;
Deck::Deck() {
    allCards_ = new Card*[CARDS_IN_DECK];
    Card* newCard;
    int i = 0;
    for (unsigned suit=CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank=ACE; rank <= KING; ++rank) {
            newCard = new Card(Suit(suit), Rank(rank));
            allCards_[i] = newCard;
            i++;
        }
    }
}

Deck::~Deck() {
    for (int i = 0; i<CARDS_IN_DECK ; i++) {
        delete allCards_[i];
    }
    delete allCards_;
}

Card** Deck::getDeck() const {
    return allCards_;
}

void Deck::newRound() {
    shuffleCards();

    for (unsigned suit=CLUB; suit <= SPADE; ++suit) {
        for (unsigned rank=ACE; rank<= KING; ++rank) {
            onTable_[suit][rank] = NULL;
        }
    }
}

void Deck::shuffleCards() {
    int seed = 0;
    static mt19937 rng(seed);

    int n = CARDS_IN_DECK;

    while ( n > 1 ) {
        int k = (int) (rng() % n);
        --n;
        Card *c = allCards_[n];
        allCards_[n] = allCards_[k];
        allCards_[k] = c;
    }
}

void Deck::play(Card *card) {
    assert(card!=NULL);
    onTable_[card->getSuit()][card->getRank()] = card;
    latestCard = card; 
}
