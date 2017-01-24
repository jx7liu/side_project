#include <iostream>
#include <string>
#include "grid.h"
#include "cell.h"
#include "textdisplay.h"
#include <stdexcept>
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;
  int moves = 0;

  // You will need to make changes this code.
  try{
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
    }
    else if (cmd == "init") {
     int row, col;
     while(true) {
     cin >> row; cin >> col;
     if (row == -1 && col == -1){
      break;
      }
      g.turnOn(row, col);  
      }
      cout << g;
    }
    else if (cmd == "game") {
      cin >> moves;
      cout << moves << " moves left" << endl;
    }
    else if (cmd == "switch") {
      int r = 0, c = 0;
      cin >> r >> c;
      g.toggle(r, c);
      cout << g;
      moves--;
      if (moves > 0) {

      cout << moves << " moves left"<<endl;
     
      }
      else {
      cout << 0 << " moves left" << endl;
       if (g.isWon()) {
          cout << "Win" <<endl;
  }
         else {

           cout <<"Lost" <<endl;
 }
    break;
      }
    }
    else {
     cin.clear();
     cin.ignore();
     }
  }
}
catch (ios:: failure &){
}

}

