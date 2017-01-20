#ifndef _OSAP_H_
#define _OSAP_H_
#include "nonproperty.h"
#include <string>

class Display;
class Player;

class OSAP: public NonProperty {
   public:
  OSAP (Display * d, std:: string name, int position);
  
  void collect (Player * p);
  
  ~ OSAP ();




};

#endif
