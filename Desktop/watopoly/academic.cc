#include "academic.h"
#include <vector>
#include <string>
#include "display.h"
using namespace std;

Academic::Academic(Display *d, string name, string owner, const int pcost,
    bool mortgage, const int type, const int icost, vector <int> * iv, int  curinum):
    Building(d, name, owner, pcost, mortgage, type), icost{icost}, iv{iv},  curinum{curinum} {}


Academic::~Academic() {delete iv;}


int Academic::getTuition() {
   return (*iv)[curinum];
}


void Academic::addImprovement() {
   if (curinum >= 5) {    // could improve  
    d->invalidAddImprovement();}
   else { curinum ++; d->sAddImprovement();}
}


void Academic::deleteImprovement() {
 
   curinum --; d->sDeleteImprovement();
}


const int Academic::getICost() {
  return icost;
}

int Academic::getAsset() {
 return getPrice()+icost*curinum;
}

int Academic::getCurinum() {
 return curinum;
}

void Academic::changeImprovement(int i) {
 curinum = i;
}


