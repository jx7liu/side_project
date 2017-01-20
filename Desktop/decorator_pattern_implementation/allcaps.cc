#include <iostream>
#include <string>
#include "allcaps.h"
using namespace std;

//class allcaps: public Decorator {
//public:
allcaps:: allcaps (TextProcessor * t): Decorator {t} {}

void allcaps:: setSource (istream * inp) {
component->setSource(inp);
}

string allcaps:: getWord() {
string s;
s = component->getWord();
int len = s.length();

for (int i = 0; i < len; i++) {
s[i] = toupper(s[i]);
}

return s; 
}
//}; 
