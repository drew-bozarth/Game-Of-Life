/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 3 - Gamestart.cpp */

/*
This is the .cpp file for GameStart.
*/

//this statement includes the user defined file "GameStart.h" into this file
#include "GameStart.h"

/*
Function: GameStart
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
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

/*
Function: ~GameStart
Return: none
Parameters: none (default destructor)
Exceptions: none
*/
GameStart::~GameStart(){
  //destructor deleting the two arrays
  for(int i = 0; i < height; i++)
      delete[] grid[i];
  for(int i = 0; i < height+2; i++)
      delete[] gridExtend[i];
  delete[] grid;
  delete[] gridExtend;
}
/*
Function: GridRandom
Return: void (nothing is returned, the function takes in values from user and sets member variables for the class
Parameters: int (w, user input for width of grid), int (h, user input for height of grid), float (d, user input for density of the grid)
Exceptions: none
*/
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
  cout << endl;
  cout << endl;
}
/*
Function: GridFile
Return: void (nothing is returned, the function takes in a file name and reads the values and sets member variables for the class
Parameters: string (inputFilePath, the user inputs a string for the file path of the input file)
Exceptions: none
*/
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
void GameStart::updateCellStatus(char** grid, int x, int y, char status){
  grid[x][y] = status;
}
/*
Function: checkNeighbors
Return: int (number of alive neighbors a cell in the grid has)
Parameters: char** (the double array passed for the grid), int (x, the x position in the grid), int (y, the y position in the grid)
Exceptions: none
*/
int GameStart::checkNeighbors(char** grid, int xGrid, int yGrid){
  //function checks neighbors based on array input and placement in grid on x and y axis
  int LiveNeighbors = 0;
  int x = xGrid + 1;
  int y = yGrid + 1;
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
/*
Function: isAlive
Return: bool (checks if the cell in the grid is alive)
Parameters: int (x, x-coordinate in grid), int (y, y-coordinate in grid)
Exceptions: none
*/
bool GameStart::isAlive(int x, int y){
  //checks if a given spot is alive
  if (grid[x][y] == 'X'){
    return true;
  }
  else if (grid[x][y] == '-'){
    return false;
  }
}
/*
Function: isDead
Return: bool (checks if the cell in the grid is dead)
Parameters: int (x, x-coordinate in grid), int (y, y-coordinate in grid)
Exceptions: none
*/
bool GameStart::isDead(int x, int y){
  //checks if a given spot is dead
  if (grid[x][y] == 'X'){
    return false;
  }
  else if (grid[x][y] == '-'){
    return true;
  }
}
/*
Function: simulationEmpty
Return: bool (returns true if all the cells in the grid are dead)
Parameters: none
Exceptions: none
*/
bool GameStart::simulationEmpty(){
  for (int x = 0; x < width; ++x){
    for (int y = 0; y < height; ++y){
      if (grid[x][y] == 'X'){
        return false;
      }
    }
  }
  return true;
}
/*
Function: nextGeneration
Return: char (either 'X' or '-' for an alive or dead cell)
Parameters: char (current, the current state of the cell), int (neighbors, the amount of neighbors the cell has)
Exceptions: none
*/
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
/*
Function: getFilePath
Return: string (returns the filePath member variable)
Parameters: none
Exceptions: none
*/
string GameStart::getFilePath(){
  //returns file path
  return inputFilePath;
}
