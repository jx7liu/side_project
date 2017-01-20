#ifndef _NONPROPERTY_H_
#define _NONPROPERTY_H_
#include <string>
#include "square.h"

class Display;

class NonProperty: public Square  {

   std:: string name;
   int position;
   public:
   static int cupnum;
   NonProperty(Display *d, std:: string name, int position);
   std:: string getName() override ;
   int getcupnum();
   int getposition();
   ~NonProperty();
};

#endif 
