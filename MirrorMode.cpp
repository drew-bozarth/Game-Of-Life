#include "MirrorMode.h"
#include "GameStart.h"

MirrorMode::MirrorMode(){
  // default constructor
}

MirrorMode::MirrorMode(int w, int h, float d){
  GameStart *game = new GameStart();
  game->GridRandom(w,h,d);
}

MirrorMode::MirrorMode(string filePath){
  GameStart *game = new GameStart();
  game->GridFile(filePath);
}

MirrorMode::~MirrorMode(){
  // destructor
}

void MirrorMode::runMirrorSimulation(){
  cout << "Running Mirror Mode Simulation" << endl;
  int neighbors = 0;
  char current;
  // gridExtend = new char*[height+1];
  // for(int i = 0; i < height+1; i++){
  //   gridExtend[i] = new char[width+1];}
  for (int j = 0; j < height; ++j){
    for (int k = 0: k < width; ++j){
        gridExtend[j+1][k+1] = grid[j][k];
      }
    };
  gridExtend[0][0] = grid[0][0];
  gridExtend[height][width] = grid[height-1][width-1];
  gridExtend[0][width] = grid[0][width-1];
  gridExtend[height][0] = grid[height-1][0];

  for (int i = 0; i < width; ++i){
    gridExtend[0][i] = grid[0][i];
    gridExtend[height][i] = grid[height-1][i];
  };
  for (int i = 0; i < height; ++i){
    gridExtend[i][0] = grid[i][0];
    gridExtend[i][width] = grid[i][width-1] ;
  };
  for (int j = 0; j < width; ++j){
    for (int k = 0: k < height; ++j){
      current = grid[j][k];
        neighbors = gs->checkNeighbors(gridExtend,j,k);
        current = gs->nextGen(current,neighbors);
        grid[j][k] = current;
    }
  };
}
