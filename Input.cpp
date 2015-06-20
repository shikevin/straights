#include "Input.h"
#include <iostream>
using namespace std;

Input::Input() {
}

Command Input::getInput(bool playableCardExists, const Deck& deck, bool isFirstPlayer, const Card& card) {
    bool badInput = true;
    Command humanInput = Command();
    // Read plays by player
    cout << ">";
    cin >> humanInput;

    if(humanInput.type != RAGEQUIT && humanInput.type != DECK) {
         if (humanInput.type == QUIT) {
            throw PlayerQuitException();
        } else if (playableCardExists) {
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
        
        if (isFirstPlayer && humanInput.type == PLAY && 
                !(humanInput.card == card)) {
            throw IllegalPlayException();
        }
    } else if (humanInput.type == DECK) {
        throw PrintDeckException();
    }
    
    // return if there is valid input
    return humanInput;
}
