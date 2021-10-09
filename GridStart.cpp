#include "GridStart.h"
#include <iostream>
#include <fstream>
#include <string>

GridStart::GridStart(){
  width = 0;
  height = 0;
  grid[width][height];
}
GridStart::GridStart(int w, int h){
  width = w;
  height = h;
  grid[width][height];

}
GridStart::~GridStart(){

}

void GridStart::GridRandom(int w, int h, float d){
  width = w;
  height = h;
  density = d;
  bool isFull = false;
  grid[w][h];
  //double for loop to sort through spots
  for (int i = 0; i < width; ++i){
    for (int k = 0; k < height; ++k){
    isFull = (rand() % 100) < (d*100);
    if (isFull){
      grid[i][k] = 'X';
    } else {
      grid[i][k] = '\0';
    }
  }}
}

 void GridStart::GridFile(string inputFile){
   FILE* input = fopen(inputFile.c_str(), "r");
   if (input != nullptr){
     char current;
     string str;
     int w;
     int h;
     int count = 0;
     getline(input,str);
     w = stoi(str);
     getline(input,str);
     h = stoi(str);
     grid[w][h];
     for (int i = 0; i < w; ++i){
       for (int k = 0; k < h; ++k){
         current = getc(input);
         if (current == '-'){
           grid[i][k] = '\0';
         } else if (current == 'x' || current == 'X'){
           grid[i][k] = current;
         } else {
           cout << "invalid input" << endl;
         }
         count++;
       }}
       fclose(inputFile);

   } else {
     cout << "No file found, please enter again" << endl;
   }};


//https://www.delftstack.com/howto/cpp/read-file-char-by-char-cpp/
