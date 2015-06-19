#ifndef _PRINT_
#define _PRINT_

#include <string>
#include "Player.h"
#include "Deck.h"

class Print {
public:
	Print();
    void notifyStart(int player);
    void printCardsOnTable(const Deck&);
    void printHumanHand(const Player&);
    void printLegalPlays(Player *, Card*);
private:
};

#endif
