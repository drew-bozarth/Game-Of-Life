/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - DoughnutMode.h */

/*
This is the header file for the DoughnutMode class which
*/

//these are the header guards to prevent the header file from being included multiple times
#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

//the are the system defined libraries that are included to be used for this class
#include <iostream>
#include <string>
#include <fstream>
// standard namespace library in C++
using namespace std;

/*
Class: DoughnutMode
Return: none
Parameters: none
Exceptions: none
*/
class DoughnutMode{
  //This is declaring the public methods and constructors and variables for the class
public:
  DoughnutMode();
  DoughnutMode(int width, int height, float density);
  DoughnutMode(string filePath);
  ~DoughnutMode();
  void runDoughnutSimulation(char selection);
private:
  //This is declaring the private variables for the class
  int width;
  int height;
  float density;
  string inputFilePath;
};
//this is the end to the header guard
#endif
