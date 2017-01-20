#include "dice.h"
#include <cstdlib>
#include "time.h"
#include <iostream>
using namespace std;



int rollDice () {
srand (time (0));
int n = rand ()% 6 + 1;
cout << "You rolled " << n << endl;
return n;
}

int rollDice2 () {
srand (time (0) - 384);
int n = rand () % 6 + 1;
cout << "You rolled " << n << endl;
return n;

}
