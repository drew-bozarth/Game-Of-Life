/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - main.cpp */

#include "Simulation.h"

using namespace std;

int main(int argc, char** argv){

  Simulation *sim = new Simulation();
  sim->start();
  //GameStart *game = new GameStart();
  //game->GridFile("input.txt");
  // gs->GridRandom(5, 7, 0.15);

  //delete game;
  delete sim;
  return 0;
}
