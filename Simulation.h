/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - Simulation.h */

/*
This is the header file for the Simulation class which
*/

//these are the header guards to prevent the header file from being included multiple times
#ifndef SIMULATION_H
#define SIMULATION_H

//the are the system defined libraries that are included to be used for this class
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
// standard namespace library in C++
using namespace std;

/*
Class: Simulation
Return: none
Parameters: none
Exceptions: none
*/
class Simulation{
  //This is declaring the public methods and constructors and variables for the class
public:
  Simulation();
  ~Simulation();
  void start();
  int SelectMode();
  //This is declaring the private variables for the class
private:
  int modeSelection;
};
//this is the end to the header guard
#endif
