#include "MirrorMode.h"
#include "GameStart.h"

MirrorMode::MirrorMode(){
  // default constructor
  GameStart *game = new GameStart();
  game->width = 0;
  game->height = 0;
  game->density = 0;
  game->inputFilePath = "";
}

MirrorMode::MirrorMode(int w, int h, float d){
  GameStart *game = new GameStart();
  // game->GridRandom(w,h,d);
  game->width = w;
  game->height = h;
  game->density = d;
}

MirrorMode::MirrorMode(string filePath){
  GameStart *game = new GameStart;
  // game->GridFile(filePath);
  game->inputFilePath = filePath;
}

MirrorMode::~MirrorMode(){
  // destructor
}

void MirrorMode::runMirrorSimulation(char selection){
  cout << "Running Mirror Mode Simulation" << endl;
  GameStart *game;
  int h = game->height;
  int w = game->width;
  if (selection = 's'){
  game->GridFile(game->inputFilePath);
} else if (selection = 'r'){
  game->GridRandom(w, h, game->density);
};
  int neighbors = 0;
  char current;
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++j){
        game->gridExtend[j+1][k+1] = game->grid[j][k];
      }
    };
  game->gridExtend[0][0] = game->grid[0][0];
  game->gridExtend[h][w] = game->grid[h-1][w-1];
  game->gridExtend[0][w] = game->grid[0][w-1];
  game->gridExtend[h][0] = game->grid[h-1][0];

  for (int i = 0; i < w; ++i){
    game->gridExtend[0][i] = game->grid[0][i];
    game->gridExtend[h][i] = game->grid[h-1][i];
  };
  for (int i = 0; i < h; ++i){
    game->gridExtend[i][0] = game->grid[i][0];
    game->gridExtend[i][w] = game->grid[i][w-1] ;
  };
  for (int j = 0; j < w; ++j){
    for (int k = 0; k < h; ++j){
      current = game->grid[j][k];
        neighbors = game->checkNeighbors(game->gridExtend,j,k);
        current = game->nextGeneration(current,neighbors);
        game->grid[j][k] = current;
    }
  }
};
