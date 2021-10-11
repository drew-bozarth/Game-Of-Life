#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DoughnutMode{
public:
  DoughnutMode();
  DoughnutMode(int width, int height, float density);
  DoughnutMode(string filePath);
  ~DoughnutMode();
  void runDoughnutSimulation();
};

#endif
