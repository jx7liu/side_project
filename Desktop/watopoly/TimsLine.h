#ifndef _TIMSLINE_H_
#define _TIMSLINE_H_
#include <string>
#include "nonproperty.h"

class Display;
class Player;

class TimsLine: public NonProperty {
  public:
  TimsLine(Display *d, std:: string name, int position);
  void canMove (Player * p, int d1, int d2);
  ~TimsLine ();

};

#endif
