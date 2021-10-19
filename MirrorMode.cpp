/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - MirrorMode.cpp */

//these statements include the user defined files MirrorMode.h" and "GameStart.h" into this file
#include "MirrorMode.h"
#include "GameStart.h"

/*
Function: MirrorMode
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
MirrorMode::MirrorMode(){
  // default constructor
  width = 0;
  height = 0;
  density = 0;
  inputFilePath = "";
  currBoard = "";
  prevBoard = "";
  generationCount = 0;
  gotFileName = false;
  outputFileName = "";
}

MirrorMode::MirrorMode(int w, int h, float d){
//overlaod constructor if gamestart is random
  width = w;
  height = h;
  density = d;
  currBoard = "";
  prevBoard = "";
  generationCount = 0;
  gotFileName = false;
  outputFileName = "";
}

MirrorMode::MirrorMode(string filePath){
// overload constructor if the gamestart is a filepath
  inputFilePath = filePath;currBoard = "";
  prevBoard = "";
  generationCount = 0;
  gotFileName = false;
  outputFileName = "";
}
/*
Function: ~MirrorMode
Return: none
Parameters: none (default destructor)
Exceptions: none
*/
MirrorMode::~MirrorMode(){
  // destructor
}

void MirrorMode::runMirrorSimulation(char selection){
    //taking parameter selection and determining what gamestart we are playing with
  GameStart *game = new GameStart();
  int h = height;
  int w = width;
    //starts game based on user input
  if (selection == 'f'){
  game->GridFile(inputFilePath);
  w = game->width;
  h = game->height;
} else if (selection == 'r'){
  game->GridRandom(width, height, density);
}
  int neighbors = 0;
  char current;
  cout << endl;

  bool simulationEnd = false;
  int outputSelection = -1;
  //after creating the two boards this asks for user input to continue simulation until end or just to print one generation to a file
  while (outputSelection <= 0 || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please enter the number for how you would like to view the Simulation:" << endl;
    cout << "1. Brief pause between generations\n2. Press 'Enter' key to display next generation\n3. Output to a file" << endl;
    cin >> outputSelection;
  }
  while (!simulationEnd){
    for (int j = 0; j < h; ++j){
      for (int k = 0; k < w; ++k){
          game->gridExtend[k+1][j+1] = game->grid[k][j];
        }
      }
  // writes the non-corner sides of extened grid based on mirror rules
    for (int i = 0; i < w+1; ++i){
      game->gridExtend[i+1][0] = game->grid[i][0];
      game->gridExtend[i+1][h+1] = game->grid[i][h-1];
    }
    for (int i = 0; i < h+1; ++i){
      game->gridExtend[0][i+1] = game->grid[0][i];
      game->gridExtend[w+1][i+1] = game->grid[w-1][i] ;
    }
    //writes the corners of the extended grid based on mirror rules
  game->gridExtend[0][0] = game->grid[0][0];
  game->gridExtend[w+1][h+1] = game->grid[w-1][h-1];
  game->gridExtend[0][h+1] = game->grid[0][h-1];
  game->gridExtend[w+1][0] = game->grid[w-1][0];

    if (outputSelection == 1) {
      //using brief pause between generations
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < h; ++j){
        for (int k = 0; k < w; ++k){
          cout << "[" << game->grid[k][j] << "]";
        }
        cout << "\n";
      }

      this_thread::sleep_for(.5s); //pauses for .5 seconds between generation outputs

    }
    else if (outputSelection == 2){
      //pressing "enter" to continue
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < h; ++j){
        for (int k = 0; k < w; ++k){
          cout << "[" << game->grid[k][j] << "]";
        }
        cout << "\n";
      }

      cout << "Press the 'Enter' key to continue" << endl;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin.get();
    }
    else if (outputSelection == 3){
      //prints to a file
      if (!gotFileName){
        cout << "Enter the name of the file you would like to write the output to: " << endl;
        cin >> outputFileName;
        gotFileName = true;
        ofstream outputFile (outputFileName);
        outputFile << "";
      }
      ofstream outputFile;
      outputFile.open(outputFileName, std::ios_base::app);

      if(outputFile.is_open()){
        outputFile << "\nGENERATION " << generationCount << "\n\n";
        for (int j = 0; j < h; ++j){
          for (int k = 0; k < w; ++k){
            outputFile << "[" << game->grid[k][j] << "]";
          }
          outputFile << "\n";
        }
      }
      else{
        throw runtime_error("Could not open output file!!");
      }
    }

    currBoard = game->BoardToString(game->grid);

    //after output method, we compute the next generation
    for (int j = 0; j < w; ++j){
      for (int k = 0; k < h; ++k){
        char currentCell = game->grid[j][k];
        int neighborCount = game->checkNeighbors(game->gridExtend,j,k);
        char newCell = game->nextGeneration(currentCell,neighborCount);
        game->updateCellStatus(game->grid,j,k,newCell);
      }
    }
    ++generationCount;
    prevprevBoard = prevBoard;
    prevBoard = currBoard;
    currBoard = game->BoardToString(game->grid);

    //check if loop needs to end & set simulationEmpty to true & close file
    if (game->simulationEmpty()){
      simulationEnd = true;
      //outputFile.close(); //this doesn't work bc its out of the scope
    }
    //check if the previous generation and the current generation are the exact same
    if (prevBoard.compare(currBoard) == 0){
      cout << "Simulation Stabilized!" << endl;
      simulationEnd = true;
    }
    //check if the generation before the previous generation is the same as the current generation,
    // because that would mean the simulation is oscilating
    else if (prevprevBoard.compare(currBoard) == 0){
      cout << "Simulation is Oscilating!" << endl;
      simulationEnd = true;
    }
  }
  cout << "GAME OVER!!!" << endl;
  delete game;
}
