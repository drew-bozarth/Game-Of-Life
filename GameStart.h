/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - Gamestart.h */
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
  ~GameStart();
  void GridRandom(int w, int h, float d);
  void GridFile(string inputFilePath);
  int checkNeighbors(char** grid, int x, int y);
  void extendGrid();
  bool isAlive(int x, int y);
  bool isDead(int x, int y);
  char nextGeneration(char current, int neighbors);
  string getFilePath();
  char** grid;
  char** gridExtend;
  int height;
  int width;
  float density;
  string inputFilePath;
private:

};

#endif
