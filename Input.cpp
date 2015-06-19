#include "Input.h"
#include <iostream>
using namespace std;

Input::Input() {
}

Command Input::getInput(bool playableCardExists, const Deck& deck) {
    bool badInput = true;
    Command humanInput = Command();
    // Read plays by player
    cout << ">";
    cin >> humanInput;

    if (humanInput.type == QUIT) {
        throw PlayerQuitException();
    } else if (humanInput.type == RAGEQUIT) {
        return humanInput;
    } else if (playableCardExists) { // player must play legal card
        if (humanInput.type == DISCARD) {
            throw LegalPlayExistsException();
        } else if (!deck.isCardPlayable(humanInput.card)) {
            throw IllegalPlayException();
        }
    } else if (!playableCardExists) {
        if (humanInput.type == PLAY) {
            throw IllegalPlayException();
        }
    }
    return humanInput;
}
