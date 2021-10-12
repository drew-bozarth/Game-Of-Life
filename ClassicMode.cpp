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
  GameStart *game = new GameStart;
  game->GridFile(filePath);
}

ClassicMode::~ClassicMode(){
  //delete game;
}

void ClassicMode::runClassicSimulation(){
  // GameStart *gs = new GameStart;
  int neighbors = 0;
  char current;
  cout << "Running Classic Mode Simulation" << endl;
  for (int j = 0; j < height; ++j){
    for (int k = 0: k < width; ++j){
      gridExtend[j+1][k+1] = grid[j][k];}}


  for (int j = 0; j < width; ++j){
    for (int k = 0: k < height; ++j){
      current = grid[j][k];
        neighbors = game->checkNeighbors(gridExtend,j,k);
        current = game->nextGen(current,neighbors);
        grid[j][k] = current;}}


            //next generation function with if statements
  }
