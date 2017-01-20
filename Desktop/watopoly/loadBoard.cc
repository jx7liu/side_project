

void loadBoard (string fileName) {

ofstream theFile;
theFile.open (fileName".txt");

int numPlayer = players->size();
theFile << numPlayer << endl;

for (int i = 0; i < numPlayer; i++) {
  theFile << "player" << i << " " << players[i]->getName() << " " << players[i]->getSelfRollUp() << " " << players[i]->getCash() << " ";
  int pos = players[i]->getLocation();
  theFile << pos << " ";
  if (pos ==10) {
  if (players[i]->isInLine) {
  theFile << 1 << " " << players[i]->getNumInLine() << endl;
  }
  else {
  theFile << 0 << endl;
  }
}
}

for (int j = 0; j < 40; j++) {
string Bname = buildings[j]->getName();
if (Bname == "OSAP" || Bname == "TUITION" || Bname == "NEEDLES HALL" || Bname == "DC Tims Line" || Bname == "COOP FEE" || Bname == "Goose Nesting" || Bname == "SLC"
    || Bname == "Go To Tims" ) {}
else {
  Building * temp = static_cast <Building *> (buildings[j]);
  if (temp->getType() == 8 || temp->getType() == 9) {
   theFile << Bname << " " << temp->getOwner() << " " << 0 << endl;
  }
  else {
   Academic * temp1 = static_cast <Academic *> (buildings[j]);
   theFile << Bname << " " << temp1->getOwner() << " " << temp1->getCurinum() << endl;
   
  }

} 

}

theFile.close(); 

}
