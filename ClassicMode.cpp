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
  //delete game;
}

void ClassicMode::runClassicSimulation(char selection){
  GameStart *game;
  if (selection = 's'){
  game->GridFile(game->inputFilePath);
} else if (selection = 'r'){
  game->GridRandom(game->width, game->height, game->density);
}
  int neighbors = 0;
  char current;
  cout << "Running Classic Mode Simulation" << endl;
  for (int j = 0; j < game->height; ++j){
    for (int k = 0: k < game->width; ++k){
      game->gridExtend[j+1][k+1] = game->grid[j][k];}}


  for (int j = 0; j < game->width; ++j){
    for (int k = 0: k < game->height; ++k){
    current = game->grid[j][k];
    neighbors = game->checkNeighbors(game->gridExtend,j,k);
    current = game->nextGen(current,neighbors);
    game->grid[j][k] = current;
  }}
