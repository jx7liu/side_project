#ifndef _PAYTUITION_H_
#define _PAYTUITION_H_
#include <string>
#include "nonproperty.h"

class Display;
class Player;

class PayTuition: public NonProperty {
public:
PayTuition (Display * d, std::string name, int position);
void pay(Player * p);
~PayTuition();

};

#endif
