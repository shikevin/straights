#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <map>

class Deck{
public:
    Deck();
    ~Deck();
    void play(Card * card);
    void newRound();
    Card** getDeck() const;
    static const int CARDS_IN_DECK = 52;
private:
    void shuffleCards();
    Card** allCards_; // should be a shuffle-able array
    Card* onTable_ [SPADE + 1][KING + 1]; // should be already sorted
    static Card* latestCardPlayed;
};

#endif
