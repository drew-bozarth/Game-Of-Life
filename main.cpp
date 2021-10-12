/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - main.cpp */

#include "Simulation.h"
#include "GridStart.h"

using namespace std;

int main(int argc, char** argv){

  Simulation *sim = new Simulation();
  sim->start();
  GridStart *gs = new GridStart();
  gs->GridFile("input.txt");
  // gs->GridRandom(5, 7, 0.15);

  delete gs;
  delete sim;
  return 0;
}
