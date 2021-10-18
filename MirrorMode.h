/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - MirrorMode.h */
#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MirrorMode{
public:
  MirrorMode();
  MirrorMode(int width, int height, float density);
  MirrorMode(string filePath);
  ~MirrorMode();
  void runMirrorSimulation(char selection);
private:
  int width;
  int height;
  float density;
  string inputFilePath;
};

#endif
