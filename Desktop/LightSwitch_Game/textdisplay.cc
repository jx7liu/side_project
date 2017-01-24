#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
theDisplay.resize(n);
for (int i = 0; i <n; i++) {
   theDisplay[i].resize(n);}
for (int i = 0; i< n; i++){
for (int j = 0; j < n; j++) {
  theDisplay[i][j] = '_';
  }
}

}

void TextDisplay::notify(Cell &c) {
int col = c.getCol();
int row = c.getRow();
//char p = theDisplay[row][col];
if (theDisplay[row][col] == 'X') {
theDisplay[row][col] = '_';
}
else {
theDisplay[row][col] = 'X';
}
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
int r = td.theDisplay.size();
for (int i = 0; i < r; i++) {
for (int j = 0; j < r; j++){
out << td.theDisplay[i][j];
}
out << endl;
}

return out;
}


