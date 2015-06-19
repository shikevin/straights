#ifndef _PRINT_
#define _PRINT_

#include <string>
#include "Player.h"
#include "Deck.h"
#include "Command.h"

class Print {
public:
	Print();
    void notifyStart(int player);
    void printCardsOnTable(const Deck&);
    void printHumanHand(const Player&);
    void printMove(int player, const Command&);
    bool printLegalPlays(const Player&, const Deck&);
private:
};

#endif
