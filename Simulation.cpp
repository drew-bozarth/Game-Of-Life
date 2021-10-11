/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - Simulation.cpp */

#include "Simulation.h"
#include "GameStart.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"


Simulation::Simulation(){
  // default constructor
  modeSelection = -1;
}

Simulation::~Simulation(){
  // destructor
}

void Simulation::start(){
  GameStart *game = new GameStart();
  try{
    bool charMatch = false;
    while (!charMatch){
      cout << "Enter 'r' if you would like to start with a random configuration, or" << endl;
      cout << "Enter 'f' if you would like to provide a flat-file for configuration: " << endl;
      char userInput;
      cin >> userInput;
      if (tolower(userInput) == 'r'){
        cout << "You selected random!" << endl;
        charMatch = true;

        int userWidth = -1;
        while (userWidth <= 0 || cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Please enter the desired width of the grid as an integer: " << endl;
          cin >> userWidth;
        }

        int userHeight = -1;
        while (userHeight <= 0 || cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Please enter the desired height of the grid as an integer: " << endl;
          cin >> userHeight;
        }

        float userDensity = -1;
        while (userDensity <= 0 || userDensity > 1 || cin.fail()){
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Please enter the desired density for the grid as a decimal between 0 and 1: " << endl;
          cin >> userDensity;
        }

        game->GridRandom(userWidth, userHeight, userDensity);
        SelectMode();
      }
      else if (tolower(userInput) == 'f'){
        cout << "You selected file input!" << endl;
        charMatch = true;

        string userFile;
        cout << "Please enter the name of the file you would like to use: " << endl;
        cin >> userFile;


        game->GridFile(userFile);
        SelectMode();
      }
    }
    delete game;
  }

  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
  }
}

void Simulation::SelectMode(){
  GameStart *game = new GameStart();
  while (modeSelection <= 0 || modeSelection > 3 || cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Please enter the number for the boundary mode you would like to run:" << endl;
    cout << "1. Classic Mode\n2. Doughnut Mode\n3. Mirror Mode" << endl;
    cin >> modeSelection;
  }

  if (modeSelection == 1){
    ClassicMode *cm = new ClassicMode();
    cm->runClassicSimulation();

    delete cm;
  }
  else if (modeSelection == 2){
    DoughnutMode *dm = new DoughnutMode();
    dm->runDoughnutSimulation();

    delete dm;
  }
  else if (modeSelection == 3){
    MirrorMode *mm = new MirrorMode();
    mm->runMirrorSimulation();

    delete mm;
  }
  else {
    cout << "Sorry, you must enter a number corresponding to the mode you would like to run." << endl;
  }

  delete game;
}
