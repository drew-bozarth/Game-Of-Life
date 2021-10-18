/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - ClassicMode.h */

/*
This is the header file for the ClassicMode class which
*/

//these are the header guards to prevent the header file from being included multiple times
#ifndef CLASSICMODE_H
#define CLASSICMODE_H

//the are the system defined libraries that are included to be used for this class
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
// standard namespace library in C++
using namespace std;

/*
Class: ClassicMode
Return: none
Parameters: none
Exceptions: none
*/
class ClassicMode{
  //This is declaring the public methods and constructors and variables for the class
public:
  ClassicMode();
  ClassicMode(int width, int height, float density);
  ClassicMode(string filePath);
  ~ClassicMode();
  void runClassicSimulation(char selection);
  // GameStart *prev1;
  // GameStart *prev2;
  // GameStart *current;
  //This is declaring the private variables for the class
private:
  int width;
  int height;
  float density;
  string inputFilePath;
};
//this is the end to the header guard
#endif
