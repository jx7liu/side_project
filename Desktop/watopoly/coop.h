#ifndef _COOP_H_
#define _COOP_H_
#include "nonproperty.h"
#include <string>

class Display;
class Player;

class Coop: public NonProperty {
  public:
  Coop(Display * d, std:: string name, int position);
  void payfee(Player *P);
  ~Coop();

};


#endif 
