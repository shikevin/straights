#ifndef _INPUT_
#define _INPUT_

#include "Deck.h"
#include <string>
#include "Command.h"

/*
responsible for controlling aspects of the game

main creates the object Table

Table has a list of players
Table has a scoreboard
Table has a deck
 */

class Input {
public:
	Input();
    Command getInput(bool, const Deck&);

    class Exception {
        public:
            Exception() {}
        private:
    };
    class PlayerQuitException : public Exception {
        public:
            PlayerQuitException() : Exception() {}
    };
    class LegalPlayExistsException : public Exception {
        public:
            LegalPlayExistsException() : Exception() {}
    };
    class IllegalPlayException : public Exception {
        public:
            IllegalPlayException() : Exception() {}
    };

private:
};
#endif
