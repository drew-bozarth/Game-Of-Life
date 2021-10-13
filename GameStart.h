#ifndef GAMESTART_H
#define GAMESTART_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

class GameStart{
public:
  GameStart();
  GameStart(int w,int h);
  ~GameStart();
  void GridRandom(int w, int h, float d);
  void GridFile(string inputFile);
  int checkNeighbors(char** grid, int x, int y);
  char** grid;
private:
  int height;
  int width;
  float density;
};

#endif
