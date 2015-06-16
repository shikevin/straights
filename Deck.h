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
private:
    static const int CARDS_IN_DECK = 52;
    Card* allCards_ [CARDS_IN_DECK]; // should be a shuffle-able array
    Card* onTable_ [SPADE][KING]; // should be already sorted
};

#endif
