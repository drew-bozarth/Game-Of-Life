#ifndef GAMERUN_H
#define GAMERUN_H

#include <iostream>
#include <string>
#include <fstream>
#include "GridStart.h"

using namespace std;

class GameRun{
public:
  GameRun();
  ~GameRun();
  int checkNeighbors(char** grid, int x, int y);
  void nextGeneration();
};

#endif
