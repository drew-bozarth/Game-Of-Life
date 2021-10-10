/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - Simulation.cpp */

#include "Simulation.h"
#include "FileReader.h"

Simulation::Simulation(){
  // default constructor
}

Simulation::~Simulation(){
  // destructor
}

void Simulation::start(){
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
        cout << "Please enter the desired width of the grid as an integer: " << endl;
        int userWidth = -1;
        cin >> userWidth;
        cout << "Please enter the desired height of the grid as an integer: " << endl;
        int userHeight = -1;
        cin >> userHeight;
        cout << "Please enter the desired density for the grid as a decimal between 0 and 1: " << endl;
        float userDensity = -1;
        cin >> userDensity;
        if (userDensity > 0 && userDensity <= 1){
          cout << "Success!" << endl;
          cout << "width: " << userWidth << endl;
          cout << "height: " << userHeight << endl;
          cout << "density: " << userDensity << endl;
          //go to grid start
          //Grid *gameGrid = new Grid(userWidth, userHeight);
        }
        else {
          cout << "Sorry you must enter an integer for the width and height, and the density as a decimal between 0 and 1." << endl;
          cout << "width: " << userWidth << endl;
          cout << "height: " << userHeight << endl;
          cout << "density: " << userDensity << endl;
        }
      }
      else if (tolower(userInput) == 'f'){
        cout << "You selected file input!" << endl;
        charMatch = true;
        FileReader *fr = new FileReader();
        //change to grid start file method

        cout << "Please enter the name of the file you would like to use: " << endl;
        string userFile;
        cin >> userFile;

        fr->readConfiguration(userFile);
        // change to grid start file method

        // run game rules with double array 

        delete fr;
      }
    }
    //delete gameGrid;
  }

  catch(runtime_error &excpt){
    cerr << excpt.what() << endl;
  }
}
