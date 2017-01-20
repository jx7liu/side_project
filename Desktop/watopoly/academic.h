#ifndef _ACADEMIC_H_
#define _ACADEMIC_H_
#include "building.h"
#include <vector>

class Display;

class Academic: public Building {
   const int icost;
   int curinum;
   std:: vector <int> * iv;
  public:
   //std:: vector <int> iv;
   Academic(Display *d, std:: string name, std:: string owner, const int pcost, bool mortgage, 
     const int type, const int icost, std:: vector  <int>* iv,  int curinum);
   ~Academic();
   int getTuition();
   void addImprovement();
   void deleteImprovement();
   const int getICost();
   int getAsset() override;
   int getCurinum();
   void changeImprovement (int i);
   };
#endif
    
