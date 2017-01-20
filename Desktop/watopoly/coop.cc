#include "coop.h"
#include <string>
#include "display.h"
#include "nonproperty.h"
#include "player.h"
using namespace std;

Coop:: Coop (Display *d, string name, int position): NonProperty {d, name, position} {}

void Coop :: payfee (Player *P) {
   d->payCoopFee();
   P->payMoney (150);

}

Coop:: ~Coop () {};
