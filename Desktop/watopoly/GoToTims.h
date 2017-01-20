#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include <string>
#include "nonproperty.h"

class Display;
class Player;

class GoToTims: public NonProperty {
  public:
  GoToTims(Display * d, std:: string name, int position);
  void toTims (Player *p);
  ~GoToTims ();


};

#endif 
