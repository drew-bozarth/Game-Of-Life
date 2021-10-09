#include "GridStart.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdlib>
#include <time.h>

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
  int value;
  bool isFull = false;
  grid[w][h];
  //double for loop to sort through spots
  //LearningLad, C Program to generate random numbers within a range of values
  //https://www.youtube.com/watch?v=ZaZxHzRn-AY
  srand(time(NULL));
  for (int i = 0; i < h; ++i){
    for (int k = 0; k < w; ++k){
    value = (rand() % 100);
    if (value <= d*100){
      isFull = true;
    } else {
      isFull = false;
    }
    if (isFull){
      cout << 'X';
      grid[k][i] = 'X';
    } else {
      cout << '-';
      grid[k][i] = '\0';
    }
  }
  cout << endl;
}
  cout << endl;
  for (int i = 0; i < w; ++i){
    for (int j = 0; j < h; ++j){
      cout << " [" << grid[i][j] << "] ";}
    cout << endl;
  };
}

 void GridStart::GridFile(string inputFile){
   ifstream input {inputFile};
   if (input.is_open()){
     char current;
     int row = 0;
     string str;
     int w;
     int h;
     getline(input,str);
     h = stoi(str);
     cout << h << endl;
     getline(input,str);
     w = stoi(str);
     cout << w << endl;
     grid[w][h];
     while(getline(input,str)){
       cout << "got line" << endl;
       // cout << str.size() << endl;
     for (int i = 0; i < str.size(); ++i){
         current = str[i];
         if (current == '-'){
           grid[i][row] = '\0';
           cout << grid[i][row] << "-";
         } else if (current == 'x' || current == 'X'){
           grid[i][row] = current;
           cout << grid[i][row];
         } else {
           cout << "invalid input" << endl;
         }
         // cout << grid[i][row];
         // grid[i][row] = current;
         // cout << current;
       }
         cout << endl;
         cout << row << endl;
       row++;}
         cout << "readfile" << endl;
         cout << grid[0][0] << endl;
       for (int k = 0; k < h; ++k){
         for (int j = 0; j < w; ++j){
           cout << " [" << grid[k][j] << "] ";
         }
         cout << endl;
       }

   } else {
     cout << "No file found, please enter again" << endl;
   }
   input.close();
   cout << "file closed" << endl;

 };


//https://www.delftstack.com/howto/cpp/read-file-char-by-char-cpp/
