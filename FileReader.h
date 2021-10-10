/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 3 - FileReader.h */


#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <string>
#include <fstream>



using namespace std;

class FileReader{

public:
  FileReader();
  ~FileReader();
  void readConfiguration(string inputFile);
};

#endif
