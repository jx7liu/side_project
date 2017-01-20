#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "display.h"
#include "bankrupt.h"
#include "building.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
using namespace std;


Player:: Player (string name, int cash, int numInLine, int sellRollUp, int location, bool inLine,  bool bankrupt): name {name},
         cash {cash}, numInLine {numInLine}, selfRollUp {selfRollUp}, location {location}, inLine {inLine}, bankrupt {bankrupt} 
           {
               d = new Display;
               myBank = new Bankrupt(d);
               myBuilding.resize(10);
               for (int i = 0; i < 10; i++) {myBuilding[i].resize(0);}
               
                             
           }

//*****************************************************************************
int Player:: getLocation () {
  return location;
}

//*****************************************************************************

string Player:: getName () {
  return name;
}

//*****************************************************************************

void Player:: setLocation (int i) {
  int temp = location + i;
  if (temp > 39) {
   location = temp - 40;
  }
  else {
   location = temp;
  }

}

//*****************************************************************************

void Player:: getMoney (int i) {
  cash += i;

}

//*****************************************************************************

void Player:: payMoney (int i) {

  if (i > cash) { //might bankrupt
   d->wantBankrupt();
   string answer;
   while (cin >> answer) {
   if (answer == "Y" || answer == "y") { 
      bankrupt = true; // want to banktrupt without selling improvements
      break;
      }
   else if (answer == "N" || answer == "n") {
      myBank->sellall( this); // selling all improvments 
      if (i > cash) {
      bankrupt = true; // tried raising money, but didnt work, bankrupt
      }
      else {
      d->raisedEnough();
      cash -= i; //else sub amount
      }
      break;
      } 
   else {
     d->invalidInput(); //invalid input
     d->wantBankrupt();
    }   

  }
  }
  else {
    cash -= i;

  }

}

//******************************************************************************

int Player:: getAsset () {
  int total = 0;
  
  for (int i = 0; i < 10; i ++) {
    int len = myBuilding[i].size();
    for (int j = 0; j <len; j++) {
     if (myBuilding[i][j]->getMortgage()) {}
     else {total += myBuilding[i][j]->getAsset();}
    }

  }
 total += cash; 

 //d->printAsset(total, name);
  return total;
}

//*****************************************************************************

void Player:: printAssets () {
  d->cash (name, cash);
  for (int i = 0; i < 10; i++) {
    int len = myBuilding[i].size();
    for (int j = 0; j < len; j++) {
     bool mort = myBuilding[i][j]->getMortgage();
     string name = myBuilding[i][j]->getName();
     int bPrice = myBuilding[i][j]->getAsset();
     if (i == 8 || i == 9) {
        if (mort) {
       d->printGymResM(name, bPrice);}
        else {d->printGymRes (name, bPrice);}
     }
    else {
      Academic * temp = static_cast <Academic *> (myBuilding[i][j]);
      int im = temp->getCurinum ();
      if (mort) { d->printAcademicM (name, bPrice,im); }
      else {d->printAcademic (name, bPrice, im);}
   }

    }
   }


}

void Player:: addBuilding(Building * b) {
   for (int i = 0; i < 10; i++){
   if (b->getType() == i ) {
     myBuilding[i].emplace_back(b);
     b->changeOwner (name);
    }
  }
}

//****************************************************************************

vector <vector <Building *>> Player:: getAllProperty () {
return myBuilding;

} 

//***************************************************************************

void Player:: makeImprovement(Building * b) {
  if (haveBuilding(b->getName()) == false) {
    d->notOwned(b->getName());
  }
  int i = b->getType();
  int len = myBuilding[i].size();
  if (max[i] != len || i == 8 || i == 9) {
   d->cannotImprove(b->getName());
  }
  else {
   Academic * temp = static_cast <Academic *> (b);
   if (temp->getICost() > cash) {d->notEnoughCash();}
   else {temp->addImprovement();
         payMoney(temp->getICost());}
  }
  
}

//*****************************************************************************

bool Player:: collectAll (int i ) {
  int len = myBuilding[i].size();
  if (len >= max[i]) {return true;}
  else {return false;}


}


//****************************************************************************

void Player:: deleteBuilding (Building * b) {
   if (haveBuilding(b->getName()) == false) {
      d->notOwned (b->getName());
    }
   int i = b->getType();
   int len = myBuilding[i].size();
   for (int j = 0; j < len; j++) {
     if (b->getName()  == myBuilding[i][j]->getName()) {
     myBuilding[i].erase(myBuilding[i].begin() + j);
     }
   }

  }

//*****************************************************************************

void Player:: sellImprovement (Building * b) {
  if (haveBuilding(b->getName()) == false) {
    d->notOwned (b->getName());
  }
  else {
   Academic * temp = static_cast <Academic *> (b);
   if (temp->getCurinum() == 0) {d->invalidDeleteImprovement();}
   else {
    temp->deleteImprovement();
    getMoney(temp->getICost()/2);}
  }

  }

//***************************************************************************

bool Player:: haveBuilding (string s) {
   for (int i = 0; i < 10; i++) {
     int len = myBuilding[i].size();
   for (int j = 0; j < len; j++) {
     if (s == myBuilding[i][j]->getName()) {
        return true;
     }
   }

   } 
    return false;

}

//***************************************************************************


int Player:: getCash () {
 return cash;

 }

//*****************************************************************************


Player:: ~Player () {
 delete myBank;
 delete d;
// for (int i = 0; i < 10; i++) {
  //int len = myBuilding[i].size();
  //for (int j = 0; j < len; j++) {
  // myBuilding[i].pop_back();
 // }
 
 // } 

}


//*****************************************************************************


int Player:: getResNum () {
return myBuilding[8].size();

}

//****************************************************************************

int Player:: getGymNum () {
return myBuilding[9].size();

}

//***************************************************************************

void Player:: addSelfRollUp () {
selfRollUp++;
}

//***************************************************************************

void Player:: removeSelfRollUp () {
selfRollUp--;
}



//**************************************************************************

void Player:: changeInLine () {
if (inLine) {

inLine = false;
}
else {
inLine = true;
}
}
//************************************************************************

bool  Player:: isInLine () {
return inLine;
}

//************************************************************************

bool Player:: getBankrupt() {
return bankrupt;
}

//***********************************************************************


void Player:: setNumInLine (int n) {
numInLine = n;

}


//****************************************************************

int Player:: getNumInLine(){
return numInLine;
}

//***********************************************************************

int Player:: getSelfRollUp () {
return selfRollUp;
}  
