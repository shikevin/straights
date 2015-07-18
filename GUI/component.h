#ifndef __COMPONENT_H
#define __COMPONENT_H

#include "Deck.h"
#include "Scoreboard.h"
#include "GameState.h"

class GameState;

class ViewComponent {
public:
	ViewComponent();
    virtual ~ViewComponent() {};
    virtual void updateView() = 0;
    void setDeck(Deck*);
    void setScoreboard(Scoreboard*);
    void setGameState(GameState*);
	
protected:
    Deck* deck;
    Scoreboard* scoreboard;
    GameState* gamestate;

private:

};

#endif
