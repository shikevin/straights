#include "Subject.h"
#include "Player.h"
#include <vector>
#include <string>

using namespace std;

class GameState : public Subject {

public: 
	int getPlayerID();
	string getPlayerType();
	void updateCurrentPlayer( Player*);

private:
	Player* currentPlayer;
};
