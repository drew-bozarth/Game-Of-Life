/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - FileReader.cpp */

#include "FileReader.h"

FileReader::FileReader(){
  // default constructor
}

FileReader::~FileReader(){
  // destructor
}

void FileReader::readConfiguration(string inputFile){
  string fileLine;
  int gridHeight;
  int gridWidth;
  ifstream input (inputFile);

  if (input.is_open()){// while loop runs while there is still a line to be read from the input file, and it is stored onto the fileLine string
    getline(input,fileLine);
    gridHeight = stoi(fileLine);
    getline(input,fileLine);
    gridWidth = stoi(fileLine);

    for (int i = 0; i < gridWidth; ++i){
      for (int j = 0; j < gridHeight; ++j){
        cout << " [" << i << "][" << j << "] ";
      }
      cout << endl;
    }

    input.close();
  }
  else {
    cout << "Error: could not open input file!" << endl;
  }
}
