#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "nonproperty.h"
#include <string>

class Display;
class Player;

class NeedlesHall: public NonProperty {
  public:
  NeedlesHall (Display *d, std:: string name, int position);
  void changePosition (Player *p);
  ~NeedlesHall ();
  
  

 };

#endif 
