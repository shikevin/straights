#include <iostream>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>

using namespace std;

    
//*******************
// main()
//*******************

int main () {
    string choices = "";
    char c; 
    for (int i = 1; i <= 4; i++) {
        cout << "Is player " << i << " a human(h) or a computer(c)?"<<endl;
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



    return 0;
}

void initilizePlayers(string instream) {
} 
