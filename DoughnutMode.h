/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - DoughnutMode.h */
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
  void runDoughnutSimulation(char selection);
private:
  int width;
  int height;
  float density;
  string inputFilePath;
};

#endif
