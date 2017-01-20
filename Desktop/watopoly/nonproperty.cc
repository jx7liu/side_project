
#include "nonproperty.h"
#include "square.h"
#include <string>
using namespace std;


NonProperty:: NonProperty (Display * d, std::string name, int position): Square{d}, name{name}, position{position}  {}

string  NonProperty:: getName() {
  return name;

}

int NonProperty:: getcupnum() {
  return cupnum;

}

int NonProperty:: getposition () {
  return position;

}

int NonProperty:: cupnum = 0; 

NonProperty::~ NonProperty() {};
