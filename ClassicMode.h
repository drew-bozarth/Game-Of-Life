/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - ClassicMode.h */

#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class ClassicMode{
public:
  ClassicMode();
  ClassicMode(int width, int height, float density);
  ClassicMode(string filePath);
  ~ClassicMode();
  void runClassicSimulation(char selection);
private:
  int width;
  int height;
  float density;
  string inputFilePath;
};

#endif
