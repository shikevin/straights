#include "Subject.h"
#include "Player.h"
#include <vector>
#include <string>
#include "Card.h"

class GameState : public Subject {

public: 
    GameState();
    virtual ~GameState();
	int getCurrentPlayerID();
    std::string getCurrentPlayerType();
	void updateCurrentPlayer( Player*);
	std::vector<Player*> getPlayersInGame();
    void nextPlayer();

private:
	Player* currentPlayer;
    static const Card startCard;
	std::vector<Player*> playersInGame;
    int currentPlayer;
};
