#include "board.h"
#include <vector>
#include "player.h"
#include <sstream>
#include <string>
#include "display.h"
#include <iostream>
#include "bankrupt.h"
#include <fstream>
#include "square.h"
#include "dice.h"
#include "building.h"
#include "academic.h"
#include "gym.h"
#include "residence.h"
#include "OSAP.h"
#include "coop.h"
#include "SLC.h"
#include "NeedlesHall.h"
#include "GoToTims.h"
#include "goosenesting.h"
#include "TimsLine.h"
#include "paytuition.h"
using namespace std;

Board::Board(Display *d, Bankrupt *bank): d{d}, bank{bank} 
{  //vector<Player *> players;
   //players.size(0);
   //vector<Square *> buildings;
   //buildings.size(0);}
}

//********************************
Board::~Board() {
  int i = players.size() - 1;
  while (i >= 0) {
    delete players[i]; 
   players.pop_back();
    i--;}
  i = 39;
 while (i >=  0) {
   delete buildings[i];
   buildings.pop_back();
   i--;}
} 

//*********************************
vector<Player *>  Board:: getPlayers() {
 return players;
}


//*********************************

void Board:: trade(Player *p, string name, string o1, string o2) {
   int n, n1,n2; string s;
   Player *p1;
   int i;
   istringstream iss1 {o1};
   istringstream iss2 {o2};
   n1 = 0;
   Building *b1; Building *b2;
   bool ep = false;
   while (n1 <players.size()) {
     if (players[n1]->getName() == name) { p1=players[n1]; ep = true; break;}
     n1++;} 
   if (!ep) {d->invalidPlayer();} //get player
   else {
    if (iss1 >> n1) { if (n1> p->getCash()) {d->notEnoughCash(); exit;}
     else {if (iss2 >> n2) {d->moneyToMoney(); exit;}
        else { b2 = getBuilding(o2); 
            if (b2 == nullptr) { d->buildingDoesNotExist(); exit;} 
            else { d->askTrade(name);
                   if (getAnswer()) {
                    if (p1->haveBuilding(o2)) { // zhuyi wenju
                      if (b2->getMortgage()) {d->cannotTradeM();}
                      else {p->payMoney(n1); p1->getMoney(n1);
                             p->addBuilding(b2); p1->deleteBuilding(b2);d->sTrade();}}
                    else {d->notOwned(o2);}}
                   else {exit;}}}}}
     else {
      if (iss2 >> n2) { 
            b1 = getBuilding(o1);
            if (b1 == nullptr) {d->buildingDoesNotExist(); exit;}
            else { if (p->haveBuilding(o1)) {
                      if (b1->getMortgage()) {d->cannotTradeM();}
                      else {d->askTrade(name);
                           if (getAnswer()) {
                             if (p1->getCash()<n2) {d->notEnoughCash(); exit;}
                             else {d->sTrade();
                                   p->getMoney(n2); p1->payMoney(n2);
                                   p->deleteBuilding(b1); p1->addBuilding(b1);}}
                            else {exit;}}}
                    else {d->notOwned(o2);}}}
       else {
            b1 = getBuilding(o1); b2 = getBuilding(o2);
            if (b1 == nullptr|| b2 == nullptr) {d->buildingDoesNotExist(); exit;}
            else {
                  if (p->haveBuilding(o1) && p1->haveBuilding(o2)) {
                    if (b1->getMortgage() || b2->getMortgage()) {d->cannotTradeM();}
                    else { d->askTrade(name);
                          if (getAnswer()) {
                               p->addBuilding(b2);p->deleteBuilding(b1);
                               p1->addBuilding(b1); p1->deleteBuilding(b2); d->sTrade();}
                          else {exit;}}}
                  else if (!(p->haveBuilding(o1))) {d->notOwned(o1);}
                  else {d->notOwned(o2);}}
                }
             }
         }
 }
///////////

void Board::initializeBoard() {
   OSAP *osap = new OSAP(d,"OSAP",0);  buildings.emplace_back(osap);
   vector <int> * v = new vector<int> {2,10,30,90,160,250};
   Academic *AL = new Academic(d,"AL","BANK", 40,false,0,50,v,0); buildings.emplace_back(AL);
   SLC *slc= new SLC(d,"SLC",2); buildings.emplace_back(slc);
   vector <int> * v1 = new vector<int> {4,20,60,180,320,450};
   Academic *ML = new Academic(d,"ML","BANK",60,false,0,50,v1,0); buildings.emplace_back(ML);
   PayTuition *tuition = new PayTuition(d,"TUITION",4); buildings.emplace_back(tuition);
   Residence *MKV = new Residence(d,"MKV","BANK", 200,false,8,25); buildings.emplace_back(MKV);
   vector <int> * v2 = new vector<int> {6,30,90,270,400,550};
   Academic *ECH = new Academic(d,"ECH","BANK", 100, false,1,50,v2,0);
   buildings.emplace_back(ECH);
   NeedlesHall *nh = new NeedlesHall(d,"NEEDLES HALL",7);
   buildings.emplace_back(nh);
   vector <int> * v3 = new vector<int> {6,30,90,270,400,550};
   Academic *pas = new Academic(d,"PAS","BANK",100,false,1,50,v3,0);
    buildings.emplace_back(pas);
   vector <int> * v4 = new vector<int>{8,40,100,300,450,600};
    Academic *hh = new Academic(d,"HH","BANK",120,false,1,50,v4,0);
    buildings.emplace_back(hh);
   TimsLine *tim = new TimsLine(d,"DC Tims Line",10);
    buildings.emplace_back(tim);
   vector <int> * v5 = new vector<int> {10,50,150,450,625, 750};
    Academic *rch = new Academic(d,"RCH","BANK",140,false,2,100,v5,0);
    buildings.emplace_back(rch);
   Gym *pac = new Gym(d,"PAC", "BANK", 150,false,9);
    buildings.emplace_back(pac);
   vector <int> * v6 = new vector<int> {10,50,150,450,625,750};
    Academic *dwe = new Academic(d,"DWE","BANK",140,false, 2,100,v6,0);
    buildings.emplace_back(dwe);
   vector <int> * v7 = new vector<int> {12,60,180,500,700,900};
    Academic *cph = new Academic(d,"CPH","BANK",160,false,2,100,v7,0);
    buildings.emplace_back(cph);
   Residence *uwp = new Residence(d,"UWP","BANK",200,false,8,25);
    buildings.emplace_back(uwp);
   vector <int> * v8 = new vector<int> {14,70,200,550,750,950};
    Academic *lhi = new Academic(d,"LHI","BANK",180,false,3,100,v8,0);
    buildings.emplace_back(lhi);
   SLC *slc2 = new SLC(d,"SLC",17);
    buildings.emplace_back(slc2);
   vector <int> * v9 = new vector<int>{14,70,200,550,750,950};
    Academic *bmh = new Academic(d,"BMH","BANK",180,false,3,100,v9,0);
    buildings.emplace_back(bmh);
   vector <int> * v10 = new vector<int> {16,80,220,600,800,1000};
    Academic *opt = new Academic(d,"OPT","BANK",200,false,3,100,v10,0);
    buildings.emplace_back(opt);
   GooseNesting *g = new GooseNesting(d,"Goose Nesting",20);
    buildings.emplace_back(g);
   vector <int> * v11 = new vector<int> {18,90,250,700,875,1050};
    Academic *e1 = new Academic(d,"EV1","BANK",220,false,4,150,v11,0);
    buildings.emplace_back(e1);
   NeedlesHall *nh2 = new NeedlesHall(d,"NEEDLES HALL",22);
    buildings.emplace_back(nh2);
   vector <int> * v12 = new vector<int> {18,90,250,700,875,1050};
    Academic *e2 = new Academic(d,"EV2","BANK",220,false,4,150,v12,0);
    buildings.emplace_back(e2);
   vector <int> * v13 = new vector<int> {20,100,300,750,925,1100};
    Academic *e3 = new Academic(d,"EV3","BANK",240,false,4,150,v13,0);
    buildings.emplace_back(e3);
   Residence *vone = new Residence(d,"V1","BANK",200,false,8,25);
    buildings.emplace_back(vone);
   vector <int> * v14 = new vector<int> {22,110,330,800,975,1150};
    Academic *p = new Academic(d,"PHYS","BANK",240,false,5,150,v14,0);
    buildings.emplace_back(p);
   vector <int> * v15 = new vector<int> {22,110,330,800,975,1150};
    Academic *b1 = new Academic(d,"B1","BANK",260,false,5,150,v15,0);
    buildings.emplace_back(b1);
   Gym *cif = new Gym(d,"CIF","BANK",150,false,9);
    buildings.emplace_back(cif);
   vector <int> * v16 = new vector<int> {24,120,360,850,1025,1200};
    Academic *b2 = new Academic(d,"B2","BANK",280,false,5,150,v16,0);
    buildings.emplace_back(b2);
   GoToTims *gtt = new GoToTims(d,"GO TO TIMS",30);
    buildings.emplace_back(gtt);
   vector <int> * v17 = new vector<int> {26,130,390,900,1100,1275};
    Academic *eit = new Academic(d,"EIT","BANK",300,false,6,200,v17,0);
    buildings.emplace_back(eit);
   vector  <int> * v18 = new vector<int> {26,130,390,900,1100,1275};
    Academic *esc = new Academic(d,"ESC","BANK",300,false,6,200,v18,0);
    buildings.emplace_back(esc);
   SLC *slc3 = new SLC(d,"SLC",33);
    buildings.emplace_back(slc3);
   vector <int> * v19 = new vector<int> {28,150,450,1000,1200,1400};
    Academic *c2 = new Academic(d,"C2","BANK",320,false,6,200,v19,0);
    buildings.emplace_back(c2);
   Residence *rev = new Residence(d,"REV","BANK",200,false,8,25);
    buildings.emplace_back(rev);
   NeedlesHall *nh3 = new NeedlesHall(d,"NEEDLES HALL",36);
    buildings.emplace_back(nh3);
   vector <int> * v20 = new vector<int> {35,175,500,1100,1300,1500};
    Academic *mc = new Academic(d,"MC","BANK",350,false,7,200,v20,0);
    buildings.emplace_back(mc);
   Coop *coop = new Coop(d,"COOP FEE",38);
    buildings.emplace_back(coop);
   vector <int> * v21 = new vector<int>{50,200,600,1400,1700,2000};
    Academic *dc = new Academic(d,"DC","BANK",400,false,7,200,v21,0);
    buildings.emplace_back(dc);
}
   
   
// ********************************
void Board::setBoard(string filename) {
ifstream file {filename};

  int numPlayer;
//char p;
string name;
int money;
int rollUp;
int position;
int numLine;
bool ifInLine = false;
file >> numPlayer;
 for (int i = 0; i < numPlayer; i++) {
  // setting an empty building vector
  //vector <vector <Building *> > v;
  //v.resize(10);
  //for (int j = 0; j < 10; j++) {v[j]->resize(0); } //might have to new the vector 
  file >> name;
  file >> name;
  file >> rollUp;
  file >> money;
  file >> position;
  if (position == 10) {
    file >> ifInLine;
    if (ifInLine) {file >> numLine; }
    else {numLine = 0;}
  }
  else {
   ifInLine = false;
   numLine = 0;
  }
  Player * temp = new Player (name, money, numLine, rollUp, position, ifInLine,false);
  players.emplace_back(temp);
}

//reading in buildings

string bname;
string owner;
int improve;

for (int k = 0; k < 40; k++) {
string Bname = buildings[k]->getName();
if (Bname == "OSAP" || Bname == "TUITION" || Bname == "NEEDLES HALL" || Bname == "DC Tims Line"
         || Bname == "COOP FEE" || Bname == "Goose Nesting" || Bname == "SLC" || Bname == "GO TO TIMS" || Bname == "Bank" ) {}
else {
      file >> bname; file >> owner; file >> improve;
  for (int l = 0; l<numPlayer; l++) {
    if (players[l]->getName() == owner) {
          Building * temp = static_cast <Building *> (buildings[k]);
          temp->changeOwner(owner);
          if (temp->getType() != 8 && temp->getType() != 9) {
           Academic * temp1 = static_cast <Academic *> (buildings[k]);
           if (improve == -1) {temp1->changeMortgage(); }
           else { temp1->changeImprovement(improve);}
          }
          else {if (improve == -1) {temp->changeMortgage();}
          }
          players[l]->addBuilding(temp);
    }

  }

}

}

}


// ********************************
void Board::loadBoard(string filename, int start) {
  ofstream theFile;
theFile.open (filename);
int count = 0;
int numP = players.size();
theFile << numP << endl;
int i = start;
while (count < numP) {
  theFile << "player" << i << " " << players[i]->getName() << " " << players[i]->getSelfRollUp() << " " << players[i]->getCash() << " ";
  int pos = players[i]->getLocation();
  theFile << pos << " ";
  if (pos == 10) {
  if (players[i]->isInLine()) {
  theFile << 1 << " " << players[i]->getNumInLine() << endl;
  count++; i++;
  if (i == numP) {i = 0;}
  }
  else {
  theFile << 0 << endl; count++; i++; 
  if (i == numP ) {i=0;}
  }
}
 else { theFile << endl; count++; i++; 
  if (i == numP) {i = 0;} }
}

for (int j = 0; j < 40; j++) {
string Bname = buildings[j]->getName();
if (Bname == "OSAP" || Bname == "TUITION" || Bname == "NEEDLES HALL" || Bname == "DC Tims Line" || Bname == "COOP FEE" || Bname == "Goose Nesting" || Bname == "SLC"
    || Bname == "GO TO TIMS" ) {}
else {
  Building * temp = static_cast <Building *> (buildings[j]);
  if (temp->getType() == 8 || temp->getType() == 9) {
      int m = 0;
    if (temp->getMortgage()) {m = -1;} 
   theFile << Bname << " " << temp->getOwner() << " " << m << endl;
  }
  else {
   Academic * temp1 = static_cast <Academic *> (buildings[j]);
    int m1 = temp1->getCurinum();
    if (temp1->getMortgage()) {
         m1 = -1;
      }
   theFile << Bname << " " << temp1->getOwner() << " " << m1  << endl;

  }

}

}

theFile.close();

}


//********************************
void Board::attachPlayer(Player *p) {
   players.emplace_back(p);
}   // how to add the first one

//*******************************
void Board::detachPlayer(Player *p) {
    string name = p->getName();
    int size = players.size();
    int i = 0;
    while (i <size) {
     if (players[i]->getName() == name) {d->detachP(players[i]->getName());delete players[i]; players.erase(players.begin()+i);return;}
     i++;}
    d->invalidPlayer();
}

////////
void Board::mortgage(Player *p, Building *b) {
  int i;
  i = b->getAsset()/2;
  if (p->haveBuilding(b->getName())) {
    if (b->getMortgage() == false) {
      if (b->getType() == 8 || b->getType() == 9) {
      p->getMoney(i);;b->changeMortgage();d->sMortgage();}
      else { 
Academic *ad = static_cast<Academic *>(b);
if (ad->getCurinum() == 0) {
               p->getMoney(i); d->sMortgage(); ad->changeMortgage();}
             else d->sellFirst();}}
    else {d->alreadyMortgage();}}
  else {d->notOwned(b->getName());}
}

////////
void Board::unmortgage(Player *p, Building *b) {
   int i;
   i = b->getAsset()*0.6;
   if (b->getMortgage() == true) {
      if (p->getName()==b->getOwner()) {
        if (i > p->getCash()) {d->notEnoughCash();}
        else {
           p->payMoney(i); d->sUnmortgage(); b->changeMortgage();}}
      else {d->notOwned(b->getName());}}
   else {d->mortgageFirst();}
}
  

//////
Building * Board:: getBuilding(string s) {
   int i = 0;
   if (s == "SLC" || s == "NEEDLES HALL" || s == "Tuition"|| s == "DC Tims Line"|| s=="Goose Nesting" || s == "GO TO TIMS" || s == "COOP FEE"|| s == "OSAP") {
  d->needBuildingType(); return nullptr;}
   else {
    while (i < 40) {
     if (s == buildings[i]->getName()) {
       Building *b = static_cast<Building *>(buildings[i]);
       return b;}
     else {i++;}}
   return nullptr;}
}

 
                               
/////////
void Board::setLocation(Player *p, int d1, int d2) {
  int sum = d1+ d2;
  if (p->isInLine() == true) {d->arriveAt("DC Tims Line");
   TimsLine *t = static_cast<TimsLine *>(buildings[10]);
    t->canMove(p,d1,d2); 
    if (p->getBankrupt() == true) {vector <vector <Building *>> temp = p->getAllProperty(); detachPlayer(p); auction(temp);};}
  else {
  int pre = p->getLocation(); 
   p->setLocation(sum); int cur = p->getLocation();
  if (pre > cur && cur != 30 && cur != 0) {
  OSAP *o = static_cast<OSAP *>(buildings[0]);
   o->collect(p);}
  if (cur == 30) {
     GoToTims *go = static_cast<GoToTims *>(buildings[30]);
     go->toTims(p);}
  else if (cur == 0) {OSAP * o1 = static_cast <OSAP *> (buildings[0]); o1->collect(p);}
  else if (cur == 10) {d->arriveAt("DC Tims Lines");}
  else if (cur == 2 || cur == 17||cur == 33) {
    SLC *slc = static_cast<SLC *>(buildings[2]);
     slc->goTo(p); setLocation(p,0,0);} // slc
  else if (cur == 7 || cur == 22 || cur == 36) {
   NeedlesHall *nh = static_cast<NeedlesHall *>(buildings[7]);
    nh->changePosition(p); 
      if (p->getBankrupt()) {vector<vector<Building *>> temp = p->getAllProperty();detachPlayer(p);
   auction(p->getAllProperty());}}  //needlles hall
  else if (cur == 38) {
    Coop *cp = static_cast<Coop *> (buildings[38]);cp->payfee(p); 
    if (p->getBankrupt()) { vector<vector<Building *>> temp = p->getAllProperty();detachPlayer(p); auction(p->getAllProperty());};}
  else if (cur == 20) {
   GooseNesting *gn = static_cast<GooseNesting *>(buildings[20]);
   gn->gooseAttack();}
  else if (cur == 4) {
   PayTuition *pt = static_cast<PayTuition *>(buildings[4]);
    pt->pay(p);
   if (p->getBankrupt()) {vector<vector<Building *>> temp=p->getAllProperty(); detachPlayer(p);auction(p->getAllProperty());};}
  else {letPay(p);}}
}
   
//////////
void Board::letPay(Player *p)  {
    int location = p->getLocation();
    Building *b = static_cast<Building *>(buildings[location]);
    int money; int num;
    if (b->getOwner() == "BANK")
      { d->arriveAt(b->getName());money = b->getPrice(); d->wannaBuy(money,b->getName());
        if (getAnswer()) {
            if (p->getCash() < money) {d->notEnoughCash();bank->auction(b,players);}
            else {p->payMoney(money);  p->addBuilding(b);}}
        else {bank->auction(b,players);}}
    else {Player *pget; int i = 0;
          string s= b->getOwner();
          while (i < players.size()) {
             if (s == players[i]->getName()) {pget = players[i];break;}
             else {i++;}}
          if (p->getName() == pget->getName()) {d->arriveAt(b->getName()); d->yourOwn();}
          else if (b->getMortgage()) {d->arriveAt(b->getName()); d->noRent();}
         
          else { if (b->getType() == 9) {
              Gym *g = static_cast<Gym *>(b);
              int d1 = rollDice(); int d2 = rollDice2();
              num = (pget->getAllProperty())[9].size();
              money = g->getFee(d1+d2, num);}
          else if (b->getType() == 8) {
             Residence *r = static_cast<Residence *>(b);
             num = (pget->getAllProperty())[8].size();
             money = r->getRent(num);}
          else {
           int type = b->getType();
           Academic *a = static_cast<Academic *>(b);
           if (p->collectAll(type) && a->getCurinum() == 0) {
                 money = a->getTuition() *2;}
          else { money = a->getTuition();}}
          d->arriveAt(b->getName());
          d->payRent(money);
          p->payMoney(money); 
       if (p->getBankrupt()) {
          transfer(p->getAllProperty(),pget);detachPlayer(p);}
       else {pget->getMoney(money);}}}
}

/////////
void Board::addIm(Player *p, Building *b) {
    if (b->getOwner() != p->getName()) {d->notOwned(b->getName());}
    else { 
      p->makeImprovement(b);
}}


/////////
void Board::deleteIm(Player *p, Building *b) {
  if (b->getOwner() != p->getName()) {d->notOwned(b->getName());}
  else { p->sellImprovement(b);
}}


//////////
void Board::assets(Player *p) {
   int i = p->getAsset();
   d->printAsset(i,p->getName());
}


////////////
void Board::all() {
  int i = 0;
  if (players.size() == 0) {cout<<"No Player"<<endl;}
  else {
  while (i < players.size()) {
    players[i]->printAssets();
    i++;}}
}

/////////
bool Board:: getAnswer() {
  char c;
  cin>>c;
   if (c == 'y' || c == 'Y') { return true;}
   else {return false;}
}


/////////
void Board::auction(vector<vector <Building *>> v) {     //may memory leak;
  int i = 0;
  while (i < v.size()) {
    int j = 0;
    while (j < v[i].size()) {
      bank->auction(v[i][j], players);
      j++;}
    i++;}
}

///////////
int Board::numPlayers() {
  return players.size();
}


//////////
void Board::transfer(vector<vector<Building *>> v, Player *p) {
   for (int i = 0; i < 10; i++) {
     int size = v[i].size();
     for (int j = 0; j < size; j++) {
       p->addBuilding(v[i][j]);}}
}



