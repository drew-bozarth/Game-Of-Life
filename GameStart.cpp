#include "GameStart.h"

GameStart::GameStart(){
  width = 100;
  height = 100;
  grid = new char*[height];
  for(int i = 0; i < height; i++)
    grid[i] = new char[width];
}
GameStart::GameStart(int w, int h){
  width = w;
  height = h;
  grid = new char*[height];
  for(int i = 0; i < width; i++)
    grid[i] = new char[width];

}
GameStart::~GameStart(){
  for(int i = 0; i < height; i++)
      delete[] grid[i];
  delete[] grid;
}

void GameStart::GridRandom(int w, int h, float d){
  width = w;
  height = h;
  density = d;
  int value;
  bool isFull = false;
  // cout << "before" << endl;
  // cout << width << " " << height << endl;
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
      grid[k][i] = '-';
    }
  }
  cout << endl;
}
  cout << grid[0][0] << endl;
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      cout << " [" << grid[j][i] << "] ";}
    cout << endl;
  };
}

void GameStart::GridFile(string inputFilePath){
  ifstream input;
  input.open(inputFilePath.c_str());
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
           grid[i][row] = current;
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
         cout << grid[0][6] << endl;
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
  int LiveNeighbors = 0;

  if (grid[x-1][y-1] != '\0')
    ++LiveNeighbors;
       //check top
  if (grid[x][y-1] != '\0')
    ++LiveNeighbors;
       //check topright
  if (grid[x+1][y-1] != '\0')
    ++LiveNeighbors;
       //check left
  if (grid[x-1][y] != '\0')
    ++LiveNeighbors;
       //check right
  if (grid[x+1][y] != '\0')
    ++LiveNeighbors;
       //check bottom left
  if (grid[x-1][y+1] != '\0')
    ++LiveNeighbors;
       //check bottom
  if (grid[x][y+1] != '\0')
    ++LiveNeighbors;
       //check bottom right
  if (grid[x+1][y+1] != '\0')
    ++LiveNeighbors;

  return LiveNeighbors;
}

void GameStart::extendGrid(){
  gridExtend = new char*[height+1];
  for(int i = 0; i < height+1; i++)
    gridExtend[i] = new char[width+1];
}

bool GameStart::isAlive(int x, int y){
  if (grid[x][y] == 'X'){
    return true;
  }
  else if (grid[x][y] == '-'){
    return false;
  }
}

bool GameStart::isDead(int x, int y){
  if (grid[x][y] == 'X'){
    return false;
  }
  else if (grid[x][y] == '-'){
    return true;
  }
}

char GameStart::nextGeneration(char current, int neighbors){
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
