#ifndef _SLC_H_
#define _SLC_H_
#include <string>
#include "nonproperty.h"


class Display;
class Player;

class SLC: public NonProperty {
  public:
  SLC (Display *d, std:: string name, int position);
  void goTo(Player *p);
  ~SLC ();


};
#endif


