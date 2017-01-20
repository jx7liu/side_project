#include "nonproperty.h"
#include "OSAP.h"
#include <string>
#include "display.h"
#include "player.h"
using namespace std;


OSAP:: OSAP (Display * d, string name, int position): NonProperty {d, name, position} {}

void OSAP:: collect (Player * p) {
d->OSAPCollection();
p->getMoney(200);

}

OSAP:: ~OSAP () {}
