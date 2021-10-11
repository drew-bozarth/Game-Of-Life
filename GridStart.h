#ifndef GRIDSTART_H
#define GRIDSTART_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

class GridStart{
public:
  GridStart();
  GridStart(int w,int h);
  ~GridStart();
  void GridRandom(int w, int h, float d);
  void GridFile(string inputFilePath);
  char** grid;
private:
  int height;
  int width;
  float density;
};

#endif
