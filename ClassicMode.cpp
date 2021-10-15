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
  cout << "in runClassicSimulation" << endl;
  GameStart *game;
  int h = game->height;
  int w = game->width;
  cout << selection << " = selection" << endl;
  if (selection == 'f'){
    cout << "in if statement" << endl;
    game->GridFile(game->getFilePath());//this has errors (game->inputFilePath)
  }
  else if (selection == 'r'){
    game->GridRandom(w, h, game->density);
  }
  int neighbors = 0;
  char current;
  cout << "Running Classic Mode Simulation" << endl;
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++k){
      game->gridExtend[j+1][k+1] = game->grid[j][k];
    }
  }


  bool simulationEmpty = false;
  int generationCount = 0;
  int outputSelection = -1;
  while (outputSelection <= 0 || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please enter the number for how you would like to view the Simulation:" << endl;
    cout << "1. Brief pause between generations\n2. Press 'Enter' key to display next generation\n3. Output to a file" << endl;
    cin >> outputSelection;
  }
  while (!simulationEmpty){
    if (outputSelection == 1) {
      //using system("pause")
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < w; ++j){
        for (int k = 0; k < h; ++j){
          cout << "[" << game->grid[j][k] << "]";
        }
        cout << "\n";
      }

      system("pause"); //press any key to continue...

    }
    else if (outputSelection == 2){
      //pressing "enter" to continue
      cout << "\n\nGENERATION " << generationCount << "\n\n";
      for (int j = 0; j < w; ++j){
        for (int k = 0; k < h; ++j){
          cout << "[" << game->grid[j][k] << "]";
        }
        cout << "\n";
      }

      cout << "Press the 'Enter' key to continue" << endl;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin.get();
    }
    else if (outputSelection == 3){
      //print to file
      string outputFileName = "";
      cout << "Enter the name of the file you would like to write the output to: " << endl;
      cin >> outputFileName;
      ofstream outputFile (outputFileName);

      if(outputFile.is_open()){
        outputFile << "\nGENERATION " << generationCount << "\n\n";
        for (int j = 0; j < w; ++j){
          for (int k = 0; k < h; ++j){
            outputFile << "[" << game->grid[j][k] << "]";
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
      for (int k = 0; k < h; ++j){
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

  delete game;
}

void ClassicMode::printGrid(){

}


//https://www.journaldev.com/41740/system-pause-command-c-plus-plus
// system("pause")
