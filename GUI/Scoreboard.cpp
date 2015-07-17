#include "Scoreboard.h"
#include "Card.h"
#include <string>
#include <cassert>
using namespace std;

// This will zero initiate the scores
Scoreboard::Scoreboard():allScores_(), newScores_() {}

void Scoreboard::discard(int player, const Card& card) {
    Rank rank = card.getRank();
    newScores_[player] += rank + 1;
}

void Scoreboard::newRound() {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        allScores_[i] = allScores_[i] + newScores_[i];
        newScores_[i] = 0;
    }
}

int Scoreboard::getCurrentScore(int player) {
    return newScores_[player];
}

int Scoreboard::getOldScore(int player) {
        return allScores_[player];
}

vector <int> Scoreboard::getLowestID() {
    int lowestScore = 1000;
    vector<int> winners;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (allScores_[i] + newScores_[i] == lowestScore) {
            winners.push_back(i);
        } else if (allScores_[i] + newScores_[i] < lowestScore) {
            winners.clear();
            winners.push_back(i);
            lowestScore = allScores_[i] + newScores_[i];
        }
    }
    return winners;

}
