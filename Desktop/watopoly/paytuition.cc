#include "nonproperty.h"
#include "paytuition.h"
#include "display.h"
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

PayTuition:: PayTuition (Display *d, string name, int position): NonProperty {d, name, position} {}

void PayTuition:: pay (Player * p) {
  d->howToPayTuition();
  string s;
  int i = p->getAsset();
  
  while (true){
  cin >> s;
  if (s == "10%") {
  p->payMoney (i * 0.1);
  break;
  }
  else if (s == "300") {
  p->payMoney (300);
  break;
  }
  else if (s == "assets") {
  d->cannotCheckAsset();
  d->howToPayTuition();
  }
  else {
  d->invalidInput();
  d->howToPayTuition();
   
  }
  }
}

PayTuition :: ~PayTuition () {}
