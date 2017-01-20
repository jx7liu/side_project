#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_
#include <string>
#include "nonproperty.h"

class Display;

class GooseNesting: public NonProperty {
  public:
  GooseNesting (Display *d, std:: string name, int num);
  void gooseAttack ();
  ~GooseNesting();
  

};

#endif
