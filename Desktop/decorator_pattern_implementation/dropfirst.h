#ifndef _DROPFIRST_H_
#define _DROPFIRST_H_

#include <iostream>
#include "decorator.h"
#include <string>

class dropfirst: public Decorator {
int drop;
public:
dropfirst (TextProcessor * t, int drop);
void setSource (std:: istream *inp) override;
std:: string getWord() override;

};

#endif 
