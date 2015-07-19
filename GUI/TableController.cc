#include "Card.h"
#include "TableController.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <vector>
#include <string>

using namespace std;

TableController::TableController(vector<ViewComponent*> views, MainWindow* a) {
    mainWindow = a;
    // input = new Input();
	deck = new Deck(); // seed goes here
	// playersInGame.reserve(4);
    // information = new Print();
	scoreboard = new Scoreboard();
    gameState = new GameState();
    validation = new Validate();
    for (int i = 0; i < views.size(); i++) {
        gameState->subscribe(views[i]);
        views[i]->setDeck(deck);
        views[i]->setScoreboard(scoreboard);
        views[i]->setGameState(gameState);
    }
    mainWindow->setGameState(gameState);
    mainWindow->setScoreboard(scoreboard);
	//currentPlayer = 0;
}

TableController::~TableController() {
    delete validation;
    validation = NULL;
    delete gameState;
    gameState = NULL;
    delete deck;
    deck = NULL;
    delete scoreboard;
    scoreboard = NULL;
}

void TableController::playGame(int seed, string choices) {
    gameState->initializePlayers(choices);
    deck->setSeed(seed);
    scoreboard->newRound();
    deck->newRound();
    distributeCards();
    gameState->newGame();
    handleComputerMove();
}

// TO-DO: IS GAME OVER??????
bool TableController::isRoundOver() {
    vector<Player*> players = gameState->getPlayersInGame();
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->getCardsInHand().size() > 0) {
            return false;
        }
    }
    return true;
}

void TableController::handleComputerMove() {
    while (!isRoundOver() && gameState->getCurrentPlayer()->getPlayerType() == "c") {
        Command command;
        command = generateComputerCommand();
        executeMove(command);
        nextPlayer();
    }
}

void TableController::playerCommand(Command command) {
    if (gameState->getCurrentPlayer()->getPlayerType() == "c" || isRoundOver()) {
        return;
    }
    // round is not over
    Command validCommand = validation->validCommand(command, doesPlayableCardExist(), *deck, gameState->isFirstPlayer(), gameState->startCard);

    executeMove(validCommand);
    nextPlayer();
    handleComputerMove();
}

void TableController::nextPlayer() {
    vector<Player*> players = gameState->getPlayersInGame();
    if (!isRoundOver()) {
        gameState->incrementPlayer();
        return;
    }

    // round is over
    for (int i = 0; i < players.size(); i++) {
        players[i]->newRound();
    }
    mainWindow->roundOver();
    // if (isGameOver()) {
    //     // pass over victors
    //     scoreboard->getLowestID();
    // }
}

Command TableController::generateComputerCommand() {
    vector<Card*> playerCards = gameState->getCurrentPlayer()->getCardsInHand();
    Command computerCommand = Command();
    if (gameState->isFirstPlayer()) {
        computerCommand.type = PLAY;
        computerCommand.card = gameState->startCard;
        return computerCommand;
    }
    for (int i = 0; i < playerCards.size(); i++) {
        if (deck->isCardPlayable(*playerCards[i])) {
            computerCommand.type = PLAY;
            computerCommand.card = Card(playerCards[i]->getSuit(), playerCards[i]->getRank());
            return computerCommand;
        }
    }
    // discard if no playable card is found
    computerCommand.type = DISCARD;
    computerCommand.card = Card(playerCards[0]->getSuit(), playerCards[0]->getRank());
    return computerCommand;
}

void TableController::executeMove(Command move) {
    Player* playerPointer = gameState->getCurrentPlayer();
    if (move.type == PLAY) {
        playerPointer->play(move.card);
        deck->play(deck->getCard(move.card));
    } else if(move.type == DISCARD) {
    	playerPointer->discard(deck->getCard(move.card));
    	scoreboard->discard(playerPointer->getPlayerID(), move.card);
    } else if(move.type == RAGEQUIT) {
        gameState->rageQuitPlayer();
        executeMove(generateComputerCommand());
    }
}

bool TableController::doesPlayableCardExist() {
    if (gameState->isFirstPlayer()) {
        return true;
    }
    bool legalCardExists = false;
    vector<Card*> playerCards = gameState->getCurrentPlayer()->getCardsInHand();
    for (int i = 0; i < playerCards.size(); i++) {
        if (deck->isCardPlayable(*playerCards[i])) {
            legalCardExists = true;
        }
    }
    return legalCardExists;
}

void TableController::distributeCards() {
    vector<Card*> shuffled = deck->getDeck();  

    for (int i = 0; i < 4 ; i++) {
        for (int j = 1; j <=13; j++) {
            gameState->getPlayersInGame()[i]->addCardToHand(shuffled[(13*i)+j-1]);
        }
    }
}

// bool Table::isGameOver() {
//     for (int i=0; i<playersInGame.size(); i++) {
//         if (scoreboard->getCurrentScore(i) + scoreboard->getOldScore(i) >= 80) {
//             return true;
//         }
//     }
//     return false;
// }
// 
// 
// void Table::playGame(string choices) {
//     // start up the game
//     initializePlayers(choices);
// 
//     try {
//         while (!isGameOver()) {
//             bool isFirstPlayer = true;
//             scoreboard->newRound();
//             deck->newRound();
//             distributeCards();
//             int start = findStartingPlayer();
// 
//             currentPlayer = start;
//             information->notifyStart(start);
//          
//             while(!isRoundOver()) {
//                 // play the game
//                 Player* playaPointa = playersInGame[currentPlayer];
//                 Command validCommand;
//                 if(playaPointa->getPlayerType() == "h") {
// 
//                     //print cards on table
//                     information->printCardsOnTable(*deck);
//                     //print player's hand
//                     information->printHumanHand(*playaPointa);
//                     //print legal plays
//                     bool playableCardExists = information->printLegalPlays(*playaPointa, *deck, isFirstPlayer);
//                     validCommand = getHumanInput(playableCardExists, isFirstPlayer);
//                 } else {
//                     //generate commands for computers
//                     validCommand = getComputerCommand(isFirstPlayer);
//                 }
//                 executeMove(validCommand, isFirstPlayer);
//                 incrementCurrentPlayer();
//                 isFirstPlayer = false;
//             }
// 
//         }
//         if (isGameOver()) {
//             information->printWinner(scoreboard->getLowestID());
//         }
//     }
//     catch (Input::PlayerQuitException &e) {
//     }
// }
// 
// Command Table::getHumanInput(bool playableCardExists, bool isFirstPlayer) {
//     Command validCommand;
//     bool success = false;
//     while(!success) {
//         try {
//             validCommand = input->getInput(playableCardExists, *deck, isFirstPlayer, startCard);
//             success = true;
//         } catch (Input::LegalPlayExistsException &e) {
//             cout << "You have a legal play. You may not discard." << endl;
//         } catch (Input::IllegalPlayException &e) {
//             cout << "This is not a legal play." << endl;
//         } catch (Input::PrintDeckException &e) {
//             information->printDeck(deck->getDeck());
//         }
//     }
//     return validCommand;
// }
// 
// 
