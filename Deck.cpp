#include "Deck.h"
#include "Card.h"
#include <string>
#include <assert.h>
#include <iostream>
#include <random>
using namespace std;

// This will zero initiate the scores
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

Card* Deck::getCard(const Card& card) {
    for (int i = 0; i < CARDS_IN_DECK; i++) {
        if (*allCards_[i] == card) {
            return allCards_[i];
        }
    }
    throw "Could not find card";
}

void Deck::play(Card *card) {
    assert(card!=NULL);
    onTable_[card->getSuit()][card->getRank()] = card;
}

ostream& operator << (ostream& sout, const Deck& deck) {
    string suits[SUIT_COUNT] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
        "7", "8", "9", "10", "J", "Q", "K"};

    for (int i = 0; i < SUIT_COUNT; i++) {
        sout << suits[i] << ": ";
        for (int j = 0; j < RANK_COUNT; j++) {
            if (deck.onTable_[i][j] != NULL) {
                sout << ranks[deck.onTable_[i][j]->getRank()] << " ";
            }
        }
        sout << endl;
    }
    return sout;
}

bool Deck::isCardPlayable(const Card& checkCard) const {
    if (checkCard.getRank() == SEVEN) {
        return true;
    } else if (checkCard.getRank() == ACE) {
        if (onTable_[checkCard.getSuit()][TWO] != NULL) {
            return true;
        }
    } else if (checkCard.getRank() == KING) {
        if (onTable_[checkCard.getSuit()][QUEEN] != NULL) {
            return true;
        }
    } else if (onTable_[checkCard.getSuit()][checkCard.getRank()-1] != NULL ||
            onTable_[checkCard.getSuit()][checkCard.getRank()+1] != NULL) {
        return true;
    }
    return false;
}
