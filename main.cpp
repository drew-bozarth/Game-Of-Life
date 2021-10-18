/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - main.cpp */

/*
This is the main file which holds the main method from which the program will
run.
*/

//this statement include the user defined files "Simulation.h" into this file
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv){

  Simulation *sim = new Simulation();
  sim->start();

  delete sim;
  return 0;
}
