#include "ClassicMode.h"
#include "GameStart.h"

ClassicMode::ClassicMode(){
  // default constructor
  GameStart *game = new GameStart();
  int width = 0;
  int height = 0;
  int desnity = 0;
  string inputFilePath = "";
}
ClassicMode::ClassicMode(int w, int h, float d){
  GameStart *game = new GameStart();
  game->GridRandom(w,h,d);
}
ClassicMode::ClassicMode(string filePath){
  GameStart *game = new GameStart();
  game->GridFile(filePath);
}

ClassicMode::~ClassicMode(){
  //delete game;
}

void ClassicMode::runClassicSimulation(){
  cout << "Running Classic Mode Simulation" << endl;

}
