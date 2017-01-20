#include "building.h"
#include "display.h"
#include <string>
#include <iostream>
using namespace std;

Building::Building(Display * d, string name, string owner, const int pcost,
  bool mortgage,const int type): Square(d), name{name}, owner{owner}, 
   pcost{pcost},  mortgage{mortgage}, type{type} {}

string Building::getName() {
  return name;}


string Building::getOwner() {
  return owner;
}


const int Building::getPrice() {
  return pcost;
}


const int Building::getType() {
  return type;
}


void  Building::changeOwner(string s) {
   owner = s;
}



void Building::changeMortgage() {
   mortgage = !mortgage;
}


bool Building::getMortgage() {
  return mortgage;
}

