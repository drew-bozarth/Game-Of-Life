#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>
#include <string>
#include <fstream>

#include "GameRun.h"

using namespace std;

class ClassicMode: public GameRun{
public:
  ClassicMode();
  ~ClassicMode();
  void runClassicSimulation();
};

#endif
