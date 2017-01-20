#include <string>
#include <cstdlib>
#include "nonproperty.h"
#include "display.h"
#include "SLC.h"
#include "time.h"
#include "player.h"
using namespace std;


SLC:: SLC (Display * d, string name, int position): NonProperty{d, name, position} {}

void SLC:: goTo(Player *p) {
d->arriveSLC();
srand(time(0)-5856);
int temp = rand()%100;
if (cupnum < 4 && temp == 0) {
d->gotACup();
cupnum++;
p->addSelfRollUp();
}
else {
temp = rand ()%24;
if (temp == 0) {
p->setLocation(-(p->getLocation()));
//p->getMoney(200);
//d->OSAPCollection();
}
else if (temp == 1) {
int cur = p->getLocation();
int y = 30 - cur;
p->setLocation(y);
//d->goToTims();
}
else if (2 <= temp && temp  <= 5) {
p->setLocation(3);
d->goForward(3);
}
else if ( 6 <= temp && temp  <= 9) {
p->setLocation(2);
d->goForward(2);
}
else if (10 <= temp && temp <= 12) {
p->setLocation(1);
d->goForward(1);
}
else if (13 <= temp && temp <= 16) {
p->setLocation (-1);
d->goBack(1);
}
else if (17 <= temp && temp <= 20) {
p->setLocation (-2);
d->goBack(2);

}
else {
int i = p->getLocation() - 3;
if (i < 0) {
p->setLocation (37);
}
else {
p->setLocation(-3);
}
d->goBack(3);
}

} 

}


SLC:: ~SLC () {};

