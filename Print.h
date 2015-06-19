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
    void notifyStart(int player)const;
    void printCardsOnTable(const Deck&)const;
    void printHumanHand(const Player&)const;
    void printMove(int player, const Command&)const;
    void printRage(int player)const;
    void printPlayerResults(int, int, int, std::vector<Card*>)const;
    bool printLegalPlays(const Player&, const Deck&)const;
    void printWinner(std::vector<int>)const;
    void printDeck(std::vector<Card*>)const;
private:
};

#endif
