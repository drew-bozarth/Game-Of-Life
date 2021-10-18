/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - ClassicMode.cpp */

//these statements include the user defined files "ClassicMode.h and "GameStart.h" into this file
#include "ClassicMode.h"
#include "GameStart.h"

/*
Function: ClassicMode
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
ClassicMode::ClassicMode(){
  //defualt constructor seeint certain variable to 0 or null;
  int width = 0;
  int height = 0;
  int density = 0;
  string inputFilePath = "";
}
ClassicMode::ClassicMode(int w, int h, float d){
  //overlaod constructor if gamestart is random
  width = w;
  height = h;
  density = d;
}
ClassicMode::ClassicMode(string filePath){
  // overload constructor if the gamestart is a filepath
  inputFilePath = filePath;
}
/*
Function: ~ClassicMode
Return: none
Parameters: none (default destructor)
Exceptions: none
*/
ClassicMode::~ClassicMode(){
  // delete game;
}

void ClassicMode::runClassicSimulation(char selection){
  //taking parameter selection and determining what gamestart we are playing with
  GameStart *game = new GameStart();
  cout << endl;
  //game start pointer
  int h = height;
  int w = width;
  // cout << selection << " = selection" << endl;
  //starts game based on user input
  if (selection == 'f'){
    game->GridFile(inputFilePath);
    w = game->width;
    h = game->height;
  }
  else if (selection == 'r'){
  game->GridRandom(width, height, density);

  }
  int neighbors = 0;
  char current;
  cout << endl;
  //writes the established gameboard to an extended version to circumvent index out of bounds when checking neighbors
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++k){
      game->gridExtend[k+1][j+1] = game->grid[k][j];
    }}
    for (int i = 0; i < w+2; ++i){
      game->gridExtend[i][0] = '-';
      game->gridExtend[i][h+1] = '-';
    };
    for (int i = 0; i < h+2; ++i){
      game->gridExtend[0][i] = '-';
      game->gridExtend[w+1][i] = '-';
    };


  bool simulationEmpty = false;
  //GameStart *currentGen;
  //GameStart *prevGen;
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
    if (outputSelection == 1) {
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < w; ++j){
        for (int k = 0; k < h; ++k){
          cout << "[" << game->grid[j][k] << "]";
        }
        cout << endl;
      }

      system("pause"); //press any key to continue...

    }
    else if (outputSelection == 2){
      //pressing "enter" to continue
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < w; ++j){
        for (int k = 0; k < h; ++k){
          cout << "[" << game->grid[j][k] << "]";
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
        for (int j = 0; j < w; ++j){
          for (int k = 0; k < h; ++k){
            outputFile << "[" << game->grid[j][k] << "]";
          }
          outputFile << "\n";
        }
      }
      else{
        throw runtime_error("Could not open output file!!");
      }
    }
    cout << "about to compute next generation" << endl;
    //after output method, we compute the next generation
    for (int m = 0; m < w; ++m){
      for (int n = 0; n < h; ++n){
        char currentCell = game->grid[m][n];
        cout << "current cell = " << currentCell << " | ";
        int neighborCount = game->checkNeighbors(game->gridExtend,m,n); //segmentation here
        cout << "neighbor count = " << neighborCount << " | ";
        char newCell = game->nextGeneration(currentCell,neighborCount);
        cout << "new cell " << newCell << " | ";
        game->updateCellStatus(game->grid,m,n,newCell);
        cout << "status = " << game->grid[m][n] << endl;
      }
    }
    ++generationCount;

    //check if loop needs to end & set simulationEmpty to true & close file
    if (game->simulationEmpty()){
      simulationEmpty = true;
      //outputFile.close(); //this doesn't work bc its out of the scope
    }
  }
  cout << "GAME OVER!!!" << endl;
  delete game;
}



//https://www.journaldev.com/41740/system-pause-command-c-plus-plus
// system("pause")
