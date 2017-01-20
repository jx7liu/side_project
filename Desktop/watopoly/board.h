
#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <string>
#include "building.h"
#include "nonproperty.h"
class Square;
class Player;
class Display;
class Bankrupt;

class Board {
 std::  vector<Square *> buildings;
  Display *d;
  Bankrupt *bank;
  std:: vector <Player *> players;
 public:
  Board(Display *d, Bankrupt *bank);
  ~Board();
  
  void trade(Player *p, std::string name, std::string o1, std::string o2); 
  
  void setBoard(std::string filename); // main need to open file and save it in f
  std::vector<Player *> getPlayers(); 
  void loadBoard(std::string filename, int i);
  void all();
  void attachPlayer(Player *p);
  void detachPlayer(Player *p);
  void mortgage(Player *p, Building *b);
  void unmortgage(Player *p, Building *b);
  void auction(std::vector <std::vector<Building *>> vb);
  bool getAnswer();
  Building *getBuilding(std::string s); 
  void setLocation(Player *p, int d1, int d2);
  void addIm(Player *p, Building *b);
  void deleteIm(Player *p, Building *b);
  void assets(Player *p);
  int numPlayers();
  void letPay(Player *p);
  void initializeBoard();
  void transfer(std::vector<std::vector<Building *>> vb,Player *p);
};

#endif
  
