#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <string>
 
class Display;

class Square {
 public:
  Display * d;
  Square (Display * d ): d {d} {} 
  virtual std:: string getName () = 0;
  virtual ~ Square () = default;

};

#endif
