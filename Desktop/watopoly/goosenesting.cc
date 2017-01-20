#include <string>
#include "goosenesting.h"
#include "display.h"
using namespace std;


GooseNesting:: GooseNesting(Display * d, string name, int num): NonProperty{d, name, num}   {}

void GooseNesting:: gooseAttack() {
  d->gooseAttack();

}

GooseNesting:: ~GooseNesting() {}  
