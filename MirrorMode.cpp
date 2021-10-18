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
  int width = 0;
  int height = 0;
  float density = 0;
  string inputFilePath = "";
}

MirrorMode::MirrorMode(int w, int h, float d){
//overlaod constructor if gamestart is random
  width = w;
  height = h;
  density = d;
}

MirrorMode::MirrorMode(string filePath){
// overload constructor if the gamestart is a filepath
  inputFilePath = filePath;
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
  cout << "Running Mirror Mode Simulation" << endl;
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


  bool simulationEmpty = false;
  int generationCount = 0;
  int outputSelection = -1;
  //after creating the two boards this asks for user input to continue simulation until end or just to print one generation to a file
  while (outputSelection <= 0 || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please enter the number for how you would like to view the Simulation:" << endl;
    cout << "1. Brief pause between generations\n2. Press 'Enter' key to display next generation\n3. Output to a file" << endl;
    cin >> outputSelection;
  }
  while (!simulationEmpty){
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
    // cout << "extended grid" << endl;
    for (int j = 0; j < h+2; ++j){
      for (int k = 0; k < w+2; ++k){
          cout << " [" << game->gridExtend[k][j] << "] ";
        }
        cout << endl;
      }
    if (outputSelection == 1) {
      //using system("pause")
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < h; ++j){
        for (int k = 0; k < w; ++k){
          cout << "[" << game->grid[k][j] << "]";
        }
        cout << "\n";
      }

      this_thread::sleep_for(.5s); //press any key to continue...

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
      string outputFileName = "";
      cout << "Enter the name of the file you would like to write the output to: " << endl;
      cin >> outputFileName;
      ofstream outputFile (outputFileName);

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

    //after output method, we compute the next generation
    for (int j = 0; j < w; ++j){
      for (int k = 0; k < h; ++k){
        current = game->grid[j][k];
          neighbors = game->checkNeighbors(game->gridExtend,j,k);
          current = game->nextGeneration(current,neighbors);
          game->grid[j][k] = current;
      }
    }
    ++generationCount;

    //check if loop needs to end & set simulationEmpty to true & close file
    if (2 == 1){
      simulationEmpty = true;
      //outputFile.close(); //this doesn't work bc its out of the scope
    }
  }
}
