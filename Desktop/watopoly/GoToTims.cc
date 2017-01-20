#include <string>
#include "GoToTims.h"
#include "display.h"
#include "nonproperty.h"
#include "player.h"
using namespace std;

GoToTims:: GoToTims (Display *d, string name, int position): NonProperty{d, name, position} {}

void GoToTims:: toTims (Player *p) {
  d->goToTims();
  p->setLocation (20);
  p->changeInLine();
}

GoToTims:: ~GoToTims () {}


 

