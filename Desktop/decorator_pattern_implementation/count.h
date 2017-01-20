#ifndef _COUNT_H_
#define _COUNT_H_
#include "decorator.h"
#include <iostream>
#include <string>
class count: public Decorator {
char c;
int counter;
public:
void setSource (std:: istream *inp) override;
count (TextProcessor * t, char c);
std:: string getWord() override;
};
#endif
