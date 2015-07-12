#ifndef _SCOREBOARD_
#define _SCOREBOARD_

#include <ostream>
#include "Card.h"
#include <istream>
#include <vector>

class Scoreboard{
public:
    Scoreboard();
    void discard(int player, const Card &);
    int getCurrentScore(int player);
    int getOldScore(int player);
    void newRound();
    std::vector<int> getLowestID();
    
private:
    static const int MAX_PLAYERS = 4;
    int allScores_ [MAX_PLAYERS];
    int newScores_ [MAX_PLAYERS];
};

#endif
