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
