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
    cout << choices;

    return 0;
}
