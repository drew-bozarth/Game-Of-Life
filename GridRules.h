#ifndef GRIDRULES_H
#define GRIDRULES_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GridRules{
public:
  GridRules();
  ~GridRules();
  void SelectMode();
private:
  unsigned int modeSelection;
};

#endif
