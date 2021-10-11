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
}
