#include <string> 
#include <cstdlib>
#include "nonproperty.h"
#include "NeedlesHall.h"
#include "display.h"
#include "time.h"
#include "player.h"
using namespace std;

NeedlesHall:: NeedlesHall (Display * d, string name, int position): NonProperty {d, name, position} {}

void NeedlesHall:: changePosition (Player * p) {
   d->arriveNeedles();
  srand(time(0));
  int temp = rand()%100;
  if (cupnum < 4 && temp == 0) {
   d->gotACup();
   cupnum++;
   p->addSelfRollUp();   
  }
 else {
  temp = rand()%18;
  if (temp == 0) {
  d->lostMoney(200);
   p->payMoney(200);
  }
  else if (temp == 1) {
  p->getMoney(200);
  d->gotMoney(200);
  }
  else if (temp == 2 || temp == 3) {
  d->lostMoney(100);
  p->payMoney(100);
  }
  else if (temp == 4 || temp == 5) {
  p->getMoney (100);
  d->gotMoney(100);
  }
  else if (temp == 6 || temp == 7 || temp == 8 ) {
  d->lostMoney(50);
  p->payMoney(50);
  }
  else if (temp == 9 || temp == 10 || temp == 11) {
  p->getMoney(50);
  d->gotMoney(50);
  }
  else {
  p->getMoney (25);
  d->gotMoney(25);
  }

  }

}

NeedlesHall:: ~NeedlesHall () {};

