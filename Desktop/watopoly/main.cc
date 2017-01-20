#include  <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "display.h"
#include "board.h"
#include "dice.h"
#include "player.h"
#include <vector>
#include "bankrupt.h"
using namespace std;

int main (int argc, char *argv[]) {
  Display *d = new Display;
  Bankrupt *bank = new Bankrupt(d);
  Board *board = new Board(d,bank);
  vector<Player *> players;
  d->welcome();
  d->askforrule();
  if (board->getAnswer()) {d->rule();}
  if (argc == 2) {
    board->initializeBoard(); 
    string fname = argv[1];
    board->setBoard(fname);};
  if (argc == 1) {
   board->initializeBoard(); 
   d->enterNumPlayer(); 
   int i;
   while (true) {
    while (!(cin>>i)) {
     d->enterNumPlayer();
     cin.clear(); cin.ignore();}
     if (i > 8) { d->tooMuchPlayer();}
     else if (i<6) { d->tooLessPlayer();}
     else {break;}} // player num set
   int n = 0;
   string s;// vector <string> vs;
   while (n < i) {
     d->enterPlayer();
     cin>>s;
     int o = 0;
     bool ex = false;
     while (o < n) {vector<Player *> temp = board->getPlayers(); if (temp[o]->getName() == s) { d->playerExist(); ex = true; break;}

                    else {o++;}}
     //vector<vector<Building *>> v;  // segmentation fault
     //v.resize(10);
     //for (int j = 0; i<10; i++) v[i].resize(0);
     if (!(ex)) {
     Player *p = new Player(s);
     board->attachPlayer(p);
     n++; }}}
    // add player;
   d->gameStart(); // i is the player num,  can use j and n;  string s;
   int j = 0;// player number.
   bool rolled = false;
   while (true) { 
    players=board->getPlayers();
    if (board->numPlayers() == 1) {d->youWin(); break;} 
    else {
      d->whoTurn(players[j]->getName());
      string s;
      cin >> s;
      if (s == "roll") { if (rolled) { d->alreadyRolled();}
        else {int d1 = rollDice(); int d2 = rollDice2();  
        board->setLocation (players[j], d1, d2); rolled = true;
        if (j == players.size()) {j = 0;}}}
       else if (s == "next") { rolled = false;
                              if (j+1 == players.size()) {j = 0;} else j++; }
       else if (s == "trade") {string p2; cin>>p2; string give; cin >> give; string receive; cin>>receive;
          board->trade(players[j],p2, give, receive);}
       else if (s == "improve") {cin >> s;
         Building *b = board->getBuilding(s);
         if (board->getBuilding(s) == nullptr) {
            d->buildingDoesNotExist();}
         else {cin>>s; if (s == "buy") {board->addIm(players[j], b);}
                else if (s == "sell") {board->deleteIm(players[j],b);}
                else {d->invalidInput();}}}
       else if (s == "mortgage") {cin >>s ;
         Building *b = board->getBuilding (s);
         if (board->getBuilding(s) == nullptr) {d->buildingDoesNotExist();}
         else { board->mortgage(players[j],b);}}
       else if (s == "unmortgage") {cin >>s;
         Building *b =board->getBuilding (s);
         if (board->getBuilding(s) == nullptr) {d->buildingDoesNotExist();}
         else {board->unmortgage(players[j],b);}}
       else if (s == "bankrupt") {d->invalidBankrupt();}
       else if (s == "assets") {
           //if (players[j]->getLocation() == 4 && rolled == false) {d->cannotCheckAsset();}
           players[j]->printAssets();}
       else if (s == "all") {
           board->all();}
       else if (s == "cash") {
          d->cash (players[j]->getName(),  players[j]->getCash());
          }
       else if (s == "save") {cin>>s;
           board->loadBoard(s,j); d->nextTime(); break;}
       else if (s == "q") {
           d->nextTimeQ();break;}
       else {d->invalidInput();}}
     }
        
    // while ends
   //int size = players.size();
   // while (size > 0) {
     // players.pop_back();
      //delete players[size];
      //cout << "delete" << size;
      //size --;}
    delete board; 
    delete bank; 
    delete d;
    
}
         
   
  
