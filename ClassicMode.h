#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class ClassicMode : public GameStart{
public:
  ClassicMode();
  ClassicMode(int width, int height, float density);
  ClassicMode(string filePath);
  ~ClassicMode();
  void runClassicSimulation();
};

#endif
