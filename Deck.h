#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <iostream>
#include <map>

class Deck{
public:
    Deck();
    ~Deck();
    void play(Card * card);
    void newRound();
    Card** getDeck() const;
    Card* getLatestCard() const;
    static const int CARDS_IN_DECK = 52;
    friend std::ostream& operator<< (std::ostream&, const Deck&);

private:
    void shuffleCards();
    Card** allCards_; // should be a shuffle-able array
    static Card* latestCard;
    Card* onTable_ [SUIT_COUNT][RANK_COUNT]; // should be already sorted

};

#endif
