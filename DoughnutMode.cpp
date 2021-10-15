#include "DoughnutMode.h"
#include "GameStart.h"

DoughnutMode::DoughnutMode(){
  // default constructor
  GameStart *game = new GameStart();
  game->width = 0;
  game->height = 0;
  game->density = 0;
  game->inputFilePath = "";
}

DoughnutMode::DoughnutMode(int w, int h, float d){
  GameStart *game = new GameStart();
  // game->GridRandom(w,h,d);
  game->width = w;
  game->height = h;
  game->density = d;
}

DoughnutMode::DoughnutMode(string filePath){
  GameStart *game = new GameStart;
  // game->GridFile(filePath);
  game->inputFilePath = filePath;
}

DoughnutMode::~DoughnutMode(){
  // destructor
}

void DoughnutMode::runDoughnutSimulation(char selection){
  cout << "Running Doughnut Mode Simulation" << endl;
  GameStart *game;
  int h = game->height;
  int w = game->width;
  if (selection = 'f'){
  game->GridFile(game->inputFilePath);
} else if (selection = 'r'){
  game->GridRandom(w, h, game->density);
};

  int neighbors = 0;
  char current;
  // gridExtend = new char*[height+1];
  // for(int i = 0; i < height+1; i++){
  //   gridExtend[i] = new char[width+1];}
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++j){
        game->gridExtend[j+1][k+1] = game->grid[j][k];
      }
    };
  game->gridExtend[0][0] = game->grid[h-1][w-1];
  game->gridExtend[h][w] = game->grid[0][0];
  game->gridExtend[0][w] = game->grid[h-1][0];
  game->gridExtend[h][0] = game->grid[0][w-1];

  for (int i = 0; i < w; ++i){
    game->gridExtend[0][i] = game->grid[h-1][i];
    game->gridExtend[h][i] = game->grid[0][i];
  };
  for (int i = 0; i < h; ++i){
    game->gridExtend[i][0] = game->grid[i][w-1];
    game->gridExtend[i][w] = game->grid[i][0];
  }

  //this creates a new generation
  bool simulationGood = true;
  int generationCount = 0;
  while (simulationGood){




    for (int j = 0; j < w; ++j){
      for (int k = 0; k < h; ++j){
        current = game->grid[j][k];
          neighbors = game->checkNeighbors(game->gridExtend,j,k);
          current = game->nextGeneration(current,neighbors);
          game->grid[j][k] = current;
      }
    }
  }



};
