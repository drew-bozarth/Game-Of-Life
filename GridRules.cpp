#include "GridRules.h"
#include "GameStart.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

GridRules::GridRules(){
  // default constructor
  modeSelection = -1;
}

GridRules::~GridRules(){
  // destructor
}

void GridRules::SelectMode(){
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
}
