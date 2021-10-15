/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - Simulation.h */


#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

class Simulation{
public:
  Simulation();
  ~Simulation();
  void start();
  int SelectMode();
private:
  int modeSelection;
};

#endif
