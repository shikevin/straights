#ifndef _DECK_
#define _DECK_

#include "Card.h"
#include <iostream>
#include <map>
#include <vector>

class Deck{
public:
    Deck(int);
    ~Deck();
    void play(const Card&);
    void newRound();
    std::vector<Card*> getDeck() const;

    friend std::ostream& operator<< (std::ostream&, const Deck&);
    bool isCardPlayable(const Card&) const;
    static const int CARDS_IN_DECK = 52;

private:
    int seed_;
    void shuffleCards();
    std::vector<Card*> allCards_; // should be a shuffle-able array
    Card* onTable_ [SUIT_COUNT][RANK_COUNT]; // should be already sorted

};

#endif
