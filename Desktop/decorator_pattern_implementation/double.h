#ifndef _DOUBLE_H_
#define _DOUBLE_H_
#include "decorator.h"
#include <string>

class Double: public Decorator {

std:: string hold;

public: 
Double (TextProcessor *t);
void setSource (std:: istream *inp) override;  
std:: string getWord () override;

};

#endif 
