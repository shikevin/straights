#include "Print.h"
#include <string>
#include <iostream>
using namespace std;

Print::Print() {
}

void Print::notifyStart(int player) {
    cout << "A new round begins. It's player " + to_string(player) + "'s turn to play." << endl;

}
