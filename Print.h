#ifndef _PRINT_
#define _PRINT_

#include <string>
#include <vector>
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
    void printRage(int player);
    void printPlayerResults(int, int, int, std::vector<Card*>);
    bool printLegalPlays(const Player&, const Deck&);
    void printWinner(std::vector<int>);
private:
};

#endif
