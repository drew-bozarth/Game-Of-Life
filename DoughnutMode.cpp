#include "DoughnutMode.h"
#include "GameStart.h"

DoughnutMode::DoughnutMode(){
  // default constructor
  // GameStart *game = new GameStart();
  width = 0;
  height = 0;
  density = 0;
  inputFilePath = "";
}

DoughnutMode::DoughnutMode(int w, int h, float d){
  // GameStart *game = new GameStart();
  // game->GridRandom(w,h,d);
  width = w;
  height = h;
  density = d;
}

DoughnutMode::DoughnutMode(string filePath){
  // GameStart *game = new GameStart;
  // game->GridFile(filePath);
  inputFilePath = filePath;
}

DoughnutMode::~DoughnutMode(){
  // destructor
}

void DoughnutMode::runDoughnutSimulation(char selection){
  cout << "Running Doughnut Mode Simulation" << endl;
  GameStart *game = new GameStart();
  int h = height;
  int w = width;
  if (selection = 'f'){
  game->GridFile(inputFilePath);
  w = game->width;
  h = game->height;
} else if (selection = 'r'){
  game->GridRandom(width, height, density);

};
cout << "height: " << h << " Width: " << w << endl;

  int neighbors = 0;
  char current;
  // gridExtend = new char*[height+1];
  // for(int i = 0; i < height+1; i++){
  //   gridExtend[i] = new char[width+1];}
  // cout << "for loop" << endl;
  for (int j = 0; j < h; ++j){
    for (int k = 0; k < w; ++k){
      // cout << "writing" << endl;
        game->gridExtend[k+1][j+1] = game->grid[k][j];
      }
    };
  game->gridExtend[0][0] = game->grid[w-1][h-1];
  game->gridExtend[w+1][h+1] = game->grid[0][0];
  game->gridExtend[0][h+1] = game->grid[w-1][0];
  game->gridExtend[w+1][0] = game->grid[0][h-1];

  for (int i = 1; i < h+1; ++i){
    game->gridExtend[0][i] = game->grid[w-1][i-1];
    game->gridExtend[w+1][i] = game->grid[0][i-1];
  };
  for (int i = 1; i < w+1; ++i){
    game->gridExtend[i][0] = game->grid[i-1][h-1];
    game->gridExtend[i][h+1] = game->grid[i-1][0];
  }

  for (int j = 0; j < h+2; ++j){
    for (int k = 0; k < w+2; ++k){
        cout << " [" << game->gridExtend[k][j] << "] ";
      }
      cout << endl;
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

}
