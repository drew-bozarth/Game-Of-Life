#ifndef GRIDSTART_H
#define GRIDSTART_H
#include <iostream>
using namespace std;

class GridStart{
public:
  GridStart();
  GridStart(int w,int h);
  ~GridStart();
  void GridRandom(int w, int h, float d);
  void GridFile(string inputFile);
  char grid[0][0];
private:
  int height;
  int width;
  float density;
};

#endif
