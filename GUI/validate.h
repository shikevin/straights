#ifndef _VALIDATE_
#define _VALIDATE_

#include "Deck.h"
#include <string>
#include "Command.h"

class Validate {
public:
	Validate();
    Command validCommand(Command, bool, const Deck&, bool, const Card&);

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
    class PrintDeckException : public Exception {
        public:
            PrintDeckException() : Exception() {}
    };

private:
};
#endif
