#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
  isOn = true;
  notifyAllObservers();
}

void Cell::toggle() {
  isOn = !isOn;
  notifyAllObservers();
  notifySwitchObservers();
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) { 
observers.push_back(o);
}

void Cell::notify(Cell & c) {
  isOn = !isOn;
  notifyAllObservers();
}


SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
int len = observers.size();
int i = 0;
while (i < len) {
if (observers[i]->subType() == SubscriptionType:: All) {
  observers[i]->notify(*this);
}
i++;

}
}

void Cell::notifySwitchObservers() {
int len = observers.size();
int j = 0;
while (j < len) {
if (observers[j]->subType() == SubscriptionType:: SwitchOnly){
   observers[j]->notify(*this);
}
j++;
}
}
