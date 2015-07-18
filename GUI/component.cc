#include "component.h"

ViewComponent::ViewComponent() {
}

void ViewComponent::setDeck(Deck* a) {
    deck = a;
}

void ViewComponent::setScoreboard(Scoreboard* a) {
    scoreboard = a;
}

void ViewComponent::setGameState(GameState* a) {
    gamestate = a;
}
