#include "DoughnutMode.h"
#include "GameStart.h"

DoughnutMode::DoughnutMode(){
  // default constructor
}

DoughnutMode::DoughnutMode(int w, int h, float d){
  GameStart *game = new GameStart();
  game->GridRandom(w,h,d);
}

DoughnutMode::DoughnutMode(string filePath){
  GameStart *game = new GameStart();
  game->GridFile(filePath);
}

DoughnutMode::~DoughnutMode(){
  // destructor
}

void DoughnutMode::runDoughnutSimulation(){
  cout << "Running Doughnut Mode Simulation" << endl;
}
