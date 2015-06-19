#include <iostream>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>

#include "Table.h"

using namespace std;

    
//*******************
// main()
//*******************

int main (int argc, char* argv[]) {
    string choices = "";
    char c; 
    for (int i = 1; i <= 4; i++) {
        cout << "Is player " << i << " a human(h) or a computer(c)?"<<endl;
        cout << ">";
        cin >> c;
        assert (c=='h' || c =='c');
        choices += c;
    }
    cout << choices << endl;

    //starts the new game
    //initializes a table that is the braniac
    //finds the player that has 7 Spades
    //loop begins:
    //print functions called depending on ttpe of player
    //play()
    //discard()
    //quit()
    //ragequit()
    //deck()

    Table braniac = Table(atoi(argv[1]));
    braniac.playGame(choices);
    return 0;
}
