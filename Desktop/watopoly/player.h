#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>

class Building;
class Display; 
class Bankrupt;

class Player {
 std:: string name;
  Display *d;
  Bankrupt *myBank;
  int cash, numInLine, selfRollUp, location;
  bool inLine, bankrupt;
  std:: vector <std::vector <Building *>> myBuilding;
  const std:: vector <int>  max {2, 3, 3, 3, 3,3,3,2,4,2};

public:
  Player (std::string name, int cash = 1500, int numInLine = 0, int selfRollUp = 0,
          int location = 0, bool inLine = false, bool bankrupt = false);
  int getLocation ();
  void printAssets();
  std:: string getName ();
  void setLocation (int i);
  void getMoney (int i);
  void payMoney (int i);//check banktupt in here 
  int getAsset ();
  void addBuilding(Building * b); 
  std:: vector <std:: vector <Building *>> getAllProperty();//getting all the properties the owner owns
  void makeImprovement(Building * b); //making improvement in a single building
   //didnt implement auction function yet
  void sellImprovement (Building * b);
  void deleteBuilding (Building * b);
  bool haveBuilding (std:: string s);
  int getCash ();
  ~Player();
  int getResNum();
  bool collectAll (int i);
  int getGymNum();
  void addSelfRollUp ();
  void removeSelfRollUp ();
  int getSelfRollUp ();
  bool isInLine();
  void changeInLine();
  bool getBankrupt(); 
  void setNumInLine (int n);
  int getNumInLine();
  
};







#endif
