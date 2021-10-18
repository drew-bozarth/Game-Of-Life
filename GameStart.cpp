/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - Gamestart.cpp */
#include "GameStart.h"

GameStart::GameStart(){
  //default constructor creating two different arrays of different sizes
  width = 100;
  height = 100;
  grid = new char*[height];
  for(int i = 0; i < height; i++)
    grid[i] = new char[width];
  gridExtend = new char*[height+2];
  for(int i = 0; i < height+2; i++){
    gridExtend[i] = new char[width+2];}
}

GameStart::~GameStart(){
  //destructor deleting the two arrays
  for(int i = 0; i < height; i++)
      delete[] grid[i];
  for(int i = 0; i < height+2; i++)
      delete[] gridExtend[i];
  delete[] grid;
  delete[] gridExtend;
}

void GameStart::GridRandom(int w, int h, float d){
  //starts a game board with heigh width and density
  width = w;
  height = h;
  density = d;
  int value;
  bool isFull = false;
  //double for loop to sort through spots
  srand(time(NULL));
  for (int i = 0; i < h; ++i){
    for (int k = 0; k < w; ++k){
      //fills in spot on board based on float given
    value = (rand() % 100);
    if (value <= d*100){
      isFull = true;
    } else {
      isFull = false;
    }
    if (isFull){
      // cout << 'X';
      grid[k][i] = 'X';
    } else {
      // cout << '-';
      grid[k][i] = '-';
    }
  }
  // cout << endl;
}
//prints grid
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      cout << " [" << grid[j][i] << "] ";}
    cout << endl;
  };
}

void GameStart::GridFile(string inputFilePath){
  //starts gameboard based on filePath input
  ifstream input;
  input.open(inputFilePath.c_str());
  if (input.is_open()){
    //checks if file exists
   char current;
   int row = 0;
   string str;
   int w;
   int h;
   getline(input,str);
   h = stoi(str);
   height = h;
   cout << h << endl;
   getline(input,str);
   w = stoi(str);
   //first two lines are the height and width
   width = w;
   cout << w << endl;
   grid[w][h];
   //restablishing gridsize with heigh and width
   while(getline(input,str)){
     // cout << "got line" << endl;
       // cout << str.size() << endl;
       //iterates through rest of file and fills in character input to the array
    for (int i = 0; i < str.size(); ++i){
         current = str[i];
         if (current == '-'){
           grid[i][row] = current;
           cout << grid[i][row] << "-";
         } else if (current == 'x' || current == 'X'){
           grid[i][row] = current;
           cout << grid[i][row];
         } else {
           cout << "invalid input" << endl;
         }
       }
         cout << endl;
         cout << row << endl;
       row++;}
         // cout << "readfile" << endl;
         // cout << grid[0][6] << endl;
         for (int i = 0; i < h; ++i){
           for (int j = 0; j < w; ++j){
             cout << " [" << grid[j][i] << "] ";}
           cout << endl;
       };

   } else {
     cout << "No file found, please enter again" << endl;
   }
   input.close();
   cout << "file closed" << endl;

}

int GameStart::checkNeighbors(char** grid, int x, int y){
  //function checks neighbors based on array input and placement in grid on x and y axis
  int LiveNeighbors = 0;

  if (grid[x-1][y-1] != '-')
    ++LiveNeighbors;
       //check top
  if (grid[x][y-1] != '-')
    ++LiveNeighbors;
       //check topright
  if (grid[x+1][y-1] != '-')
    ++LiveNeighbors;
       //check left
  if (grid[x-1][y] != '-')
    ++LiveNeighbors;
       //check right
  if (grid[x+1][y] != '-')
    ++LiveNeighbors;
       //check bottom left
  if (grid[x-1][y+1] != '-')
    ++LiveNeighbors;
       //check bottom
  if (grid[x][y+1] != '-')
    ++LiveNeighbors;
       //check bottom right
  if (grid[x+1][y+1] != '-')
    ++LiveNeighbors;

  return LiveNeighbors;
}

bool GameStart::isAlive(int x, int y){
  //checks if a given spot is alive
  if (grid[x][y] == 'X'){
    return true;
  }
  else if (grid[x][y] == '-'){
    return false;
  }
}

bool GameStart::isDead(int x, int y){
  //checks if a given spot is dead
  if (grid[x][y] == 'X'){
    return false;
  }
  else if (grid[x][y] == '-'){
    return true;
  }
}

char GameStart::nextGeneration(char current, int neighbors){
  //returns the next generation of a value based on the current character and the number of neighbors
  if (neighbors <= 1){
    return '-';
  }
  else if (neighbors == 2){
    return current;
  }
  else if (neighbors == 3){
    return 'X';
  }
  else if (neighbors >= 4){
    return '-';
  }
}

string GameStart::getFilePath(){
  //returns file path
  return inputFilePath;
}
