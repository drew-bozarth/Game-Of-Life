#ifndef GAMESTART_H
#define GAMESTART_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

class GameStart{
public:
  GameStart();
  virtual ~GameStart();
  virtual void GridRandom(int w, int h, float d);
  virtual void GridFile(string inputFilePath);
  virtual int checkNeighbors(char** grid, int x, int y);
  virtual void extendGrid();
  bool isAlive(int x, int y);
  bool isDead(int x, int y);
  virtual char nextGeneration(char current, int neighbors);
  char** grid;
  char** gridExtend;
  int height;
  int width;
  float density;
private:

};

#endif
