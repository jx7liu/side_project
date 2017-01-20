#include <iostream>
#include "dropfirst.h"
#include <string>
using namespace std;

//class dropfirst: public Decorator {
//int drop;
//public: 
dropfirst:: dropfirst(TextProcessor * t, int drop): Decorator {t}, drop{drop} {}

void dropfirst:: setSource (istream * inp) {
component->setSource(inp);

}

string dropfirst:: getWord() {

string s;
s = component->getWord();
int len = s.length();
if (drop >= len) {
s = getWord();
}
else{
s = s.substr(drop, s.length()-drop);
}
return s;
}

//};  
