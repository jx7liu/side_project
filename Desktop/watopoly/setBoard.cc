
void Board:: setBoard (string fileName) {

ifstream file {fileName};
int numPlayer;
//char p;
string name;
int money; 
int rollUp;
int position;
int numLine;
bool ifInLine;
file >> numPlayer;
 for (int i = 0; i < numPlayer; i++) {
  // setting an empty building vector
  new vector <vector <Building *> > v;
  v->resize(10);
  for (int j = 0; j < 10; j++) {v[j]->resize(0); } //might have to new the vector 
  file >> name;
  file >> name;
  file >> rollUp;
  file >> money;
  file >> position;
  if (position == 10) { 
    file >> ifInLine;
    if (ifInLine) {file >> numLine;}
    else {numLine = 0;}
  }
  else {
   ifInLine = false;
   numLine = 0;
  }
  Player * temp = new Player (name, money, numLine, rollUp, position, ifInLine, v, false); 
  players.emplace_back(temp);
}

//reading in buildings

string bname;
string owner;
int improve;

for (int k = 0; k < 40; k++) {
string Bname = buildings[k]->getName;
if (Bname == "OSAP" || Bname == "TUITION" || Bname == "NEEDLES HALL" || Bname == "DC Tims Line" 
         || Bname == "COOP FEE" || Bname == "Goose Nesting" || Bname == "SLC" || Bname == "Go To Tims" || Bname == "Bank" ) {}
else {
      file >> bname; file >> owner; file >> improve;
  for (int l = 0; l<numPlayer; l++) {
    if (players[l]->getName == owner) {
          Building * temp = static_cast <Building *> (buildings[k]);
          temp->changeOwner(owner);
          if (temp->getType() != 8 || temp->getType() != 9) {
           Academic * temp1 = static_cast <Academic *> (building[k]);
           temp1->changeImprovement(improve);
          }
          players[l]->addBuilding(temp);
    } 
 
  }

}

}

} 
