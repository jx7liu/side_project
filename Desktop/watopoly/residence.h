#ifndef _RESIDENCE_H_
#define _RESIDENCE_H_
#include "building.h"
#include <string>

class Display;

class Residence: public Building {
  const int baserent;
 public:
  Residence(Display *d, std::string name, std::string owner, const int pcost, bool mortgage,
       const int type, const int baserent);
  ~Residence();
  int getRent(int);
  int getAsset() override;};


#endif
