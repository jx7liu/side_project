#include <iostream>
#include <string>
#include <sstream>
#include "count.h"
using namespace std;


count:: count (TextProcessor * t, char c): Decorator {t}, c{c} {
counter = 0;
}

void count:: setSource (istream * inp) {
component->setSource(inp);
}

string count:: getWord () {
string s;
s = component->getWord();
int len = s.length();
int i = 0;
while (i < len) {
if (s[i] == c) {
counter++;
ostringstream ss;
ss << counter;
s = s.substr(0, i) + ss.str() + s.substr( i+1, len-1);
len = s.length();
}
i++;

}

return s;


}

