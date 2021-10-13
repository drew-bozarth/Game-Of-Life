/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - Simulation.cpp */

#include "Simulation.h"
#include "GameStart.h"
#include "GridRules.h"

Simulation::Simulation(){
  // default constructor
}

Simulation::~Simulation(){
  // destructor
}

void Simulation::start(){
  //GridStart *gs = new GridStart();
  GridRules *gr = new GridRules();
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

        //gs->GridRandom(userWidth, userHeight, userDensity);
        gr->SelectMode();
      }
      else if (tolower(userInput) == 'f'){
        cout << "You selected file input!" << endl;
        charMatch = true;

        string userFile;
        cout << "Please enter the name of the file you would like to use: " << endl;
        cin >> userFile;


        //gs->GridFile(userFile);
        gr->SelectMode();
      }
    }
    //delete gs;
    delete gr;
  }

  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
  }
}
