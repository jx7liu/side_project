#include <iostream>
#include <vector>
#include "grid.h"
using namespace std;

Grid::Grid() {
gridSize = 0;
}

Grid::~Grid() {  
clearGrid();
}

void Grid::clearGrid() {
if (gridSize == 0) {
return;
}
else {
int size = gridSize;
for (int i = 0; i <size; i ++) {
theGrid[i].clear();
}
theGrid.clear();
if (td != nullptr) {
delete td;
}

}
}

bool Grid::isWon() const {
/*bool temp = true;
for ( int i = 0; i<gridSize; i++){
for ( int j = 0; j<gridSize; j++){
if (!theGrid[i][j].getState()){
temp  = false;
break;
}
}
} 
won = temp;
*/
return won; }

void Grid::init(int n) {
clearGrid();
won = true;
theGrid.resize(n);
gridSize = n;
td = new TextDisplay(n);
for (int i = 0; i <n; i++){
theGrid[i].resize(n);}

for (int i = 0; i < n; i++){
for (int j = 0; j <n; j++) {
theGrid[i][j].setCoords(i,j);
theGrid[i][j].attach(td);
if (i != 0){
Cell * hold = &theGrid[i-1][j];
theGrid[i][j].attach(hold);
}
if (i != n-1) {
Cell * hold = &theGrid[i+1][j];
theGrid[i][j].attach(hold);
}
if (j != 0) {
Cell * hold = &theGrid[i][j-1];
theGrid[i][j].attach(hold);
}
if (j != n-1) {
Cell * hold = &theGrid[i][j+1];
theGrid[i][j].attach(hold);
}
}
}}





void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
bool temp = true;
for (int i = 0; i < gridSize; i++) {
for (int j = 0; j < gridSize; j++) {
if (!theGrid[i][j].getState()) {
temp = false;
break;
}
}
}
won = temp;
}

ostream &operator<<(ostream &out, const Grid &g) {
out << *g.td;
return out;
}
