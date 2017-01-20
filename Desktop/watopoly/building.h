#ifndef _BUILDING_H_
#define _BUILDING_H_
#include <string>
#include "square.h"
class Display;

class Building:public Square {
   std::string name, owner;
   bool mortgage;
   const int pcost;
   const int type;
  public:
   Building(Display *d,std::string name, std::string owner,const int pcost, bool mortgage,    const int type);
   virtual ~Building() = default;
   std::string getName() override;
   std::string getOwner();
   const int getPrice();
   const  int getType();
   void changeOwner(std::string s);
   void changeMortgage();
   bool getMortgage();
   virtual int getAsset() = 0;
};

#endif
