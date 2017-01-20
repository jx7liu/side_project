#include "bankrupt.h"
#include "player.h"
#include "academic.h"
#include "gym.h"
#include "residence.h"
#include <vector>
#include <string>
#include <iostream>
#include "display.h"
using namespace std;


Bankrupt::Bankrupt(Display *d): d{d} {}

Bankrupt::~Bankrupt() {}


void Bankrupt::sellall(Player *p) {
  vector<vector<Building *>> v = p->getAllProperty();
  int i = 0; int j = 0;
  int sum = 0;
  Building *a;
  while (i < 10) {
    j = 0;
    while (j < v[i].size()) {
     a = v[i][j];
     sum += (a->getAsset())*0.5;
     int n = 0;
     a->changeMortgage();
     if (i < 8) {
      Academic *ad = static_cast<Academic *>(v[i][j]);
      ad->changeImprovement(0);};
     j++;}
    i++;}
   p->getMoney(sum);
   d->everyM();
  
}


void Bankrupt::auction(Building *b, vector<Player *> v) {
     // the owner already bankrupt; not in the vector
   d->startAuction(b->getName());
   int i = 0;
   int curprice = 0; int max = 0;
   while (i< v.size()) { 
  
    if (v.size() == 1 && max != 0) {if (v[0]->getCash()<max) {d->notEnoughCash();d->failedAuction();b->changeOwner("BANK");break;}
                                   else {v[0]->payMoney(max);v[0]->addBuilding(b); d->sAuction (v[0]->getName()); break;}}
    else {d->wantedPrice(v[i]->getName());
         if (!(cin>>curprice)) {d->invalidInput();cin.clear(); cin.ignore();}
       else { 
     if (v.size() == 1 && curprice != 0) {
       {if (v[0]->getCash() < curprice) { d->notEnoughCash(); d->failedAuction(); b->changeOwner("BANK");break;}
        else  { d->sAuction(v[0]->getName()); v[0]->payMoney(curprice); v[0]->addBuilding(b);break;}}}
     else if (v.size() == 1 && curprice == 0) {d->failedAuction();b->changeOwner("BANK");break;}
     else if (curprice == 0) {d->playerQuit(v[i]->getName()); v.erase(v.begin()+i); if (i == v.size()) {i = 0;} else {};}
     else if (curprice <= max) {d->priceIsLow(); d->playerQuit(v[i]->getName()); v.erase(v.begin()+i); if ( i == v.size()) {i = 0;};}
     else if (curprice > v[i]->getCash()) { d->notEnoughCash(); v.erase(v.begin()+i); if (i == v.size()) {i = 0;};}
            else { d->playerAuction(v[i]->getName(), curprice); max = curprice; 
                   if (i+1 == v.size()) {i = 0;} else {i++;}}}}}
}


