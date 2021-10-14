#include "ClassicMode.h"
#include "GameStart.h"

ClassicMode::ClassicMode(){
  // default constructor
  GameStart *game = new GameStart();
  game->width = 0;
  game->height = 0;
  game->density = 0;
  game->inputFilePath = "";
}
ClassicMode::ClassicMode(int w, int h, float d){
  GameStart *game = new GameStart();
  // game->GridRandom(w,h,d);
  game->width = w;
  game->height = h;
  game->density = d;
}
ClassicMode::ClassicMode(string filePath){
  GameStart *game = new GameStart;
  // game->GridFile(filePath);
  game->inputFilePath = filePath;
}

ClassicMode::~ClassicMode(){
  // delete game;
}

void ClassicMode::runClassicSimulation(char selection){
  GameStart *game;
  int h = game->height;
  int w = game->width;
  if (selection = 's'){
  game->GridFile(game->inputFilePath);
} else if (selection = 'r'){
  game->GridRandom(w, h, game->density);
}
  int neighbors = 0;
  char current;
  cout << "Running Classic Mode Simulation" << endl;
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++k){
      game->gridExtend[j+1][k+1] = game->grid[j][k];
    }};


  for (int j = 0; j < w; ++j){
    for (int k = 0; k < h; ++k){
    current = game->grid[j][k];
    neighbors = game->checkNeighbors(game->gridExtend,j,k);
    current = game->nextGeneration(current,neighbors);
    game->grid[j][k] = current;
  }};
delete game;
};
