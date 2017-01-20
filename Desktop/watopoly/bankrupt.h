#ifndef _BANKRUPT_H_
#define _BANKRUPT_H_
#include <vector>

class Display;
class Building;
class Player;

class Bankrupt {
   Display *d;
  public:
   Bankrupt(Display * d);
   ~Bankrupt();
   void sellall(Player *p);
   void auction(Building *b, std:: vector<Player *> v);
};

#endif
