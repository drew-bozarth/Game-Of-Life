/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - Gamestart.h */

/*
This is the header file for the GameStart class which is used to set
up the background of the Game of Life, and is how the grid is created
and altered for the simulation
*/

//these are the header guards to prevent the header file from being included multiple times
#ifndef GAMESTART_H
#define GAMESTART_H

//the are the system defined libraries that are included to be used for this class
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
// standard namespace library in C++
using namespace std;

/*
Class: GameStart
Return: none
Parameters: none
Exceptions: none
*/
class GameStart{
//This is declaring the public methods and constructors and variables for the class
public:
  GameStart();
  ~GameStart();
  void GridRandom(int w, int h, float d);
  void GridFile(string inputFilePath);
  int checkNeighbors(char** grid, int x, int y);
  void extendGrid();
  void updateCellStatus(char** grid, int x, int y, char status);
  bool isAlive(int x, int y);
  bool isDead(int x, int y);
  bool simulationEmpty();
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
//this is the end to the header guard
#endif
