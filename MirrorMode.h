/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - MirrorMode.h */

/*
This is the header file for the MirrorMode class which
*/

//these are the header guards to prevent the header file from being included multiple times
#ifndef MIRRORMODE_H
#define MIRRORMODE_H

//the are the system defined libraries that are included to be used for this class
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
// standard namespace library in C++
using namespace std;

/*
Class: MirrorMode
Return: none
Parameters: none
Exceptions: none
*/
class MirrorMode{
  //This is declaring the public methods and constructors and variables for the class
public:
  MirrorMode();
  MirrorMode(int width, int height, float density);
  MirrorMode(string filePath);
  ~MirrorMode();
  void runMirrorSimulation(char selection);
  int generationCount;
  //This is declaring the private variables for the class
private:
  int width;
  int height;
  float density;
  string inputFilePath;
  string currBoard;
  string prevBoard;
  string prevprevBoard;
};
//this is the end to the header guard
#endif
