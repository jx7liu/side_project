#include <iostream>
#include "double.h"
#include <string>
using namespace std;

Double:: Double(TextProcessor * t): Decorator {t} {
hold = "";
}

void Double:: setSource (istream * inp) {
component->setSource(inp);
}
string Double:: getWord () {
if (hold == "") {
string s;
s = component->getWord();
hold = s;
return s;
}

else {
string s = hold;
hold = "";
return s;
}

}

