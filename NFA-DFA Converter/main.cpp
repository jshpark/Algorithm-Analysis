// https://www.geeksforgeeks.org/power-set/

#include "FileIO.h"
#include "ListNodeSingle.h"
#include "SingleLinkedList.h"
#include "LO_States.h"
#include "LO_Symbols.h"
#include "SO_Accepts.h"
#include "StartState.h"
#include "TransitionFunc.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  FileIO checkFile;
  ifstream readFile;
  ofstream writeFile;
  if (checkFile.CheckArg(argc) == -1)
  {
    return 0;
  }
  if (checkFile.ReadFileOpen(readFile, argv[1]) == -1)
  {
    return 0;
  }

  Simulation simulation;
  string fileName = argv[1];
  readFile.open(fileName);
  writeFile.open("Results.DFA");

  simulation.convertSetofStates(readFile, writeFile);
  simulation.convertListofSymbols(readFile, writeFile, fileName);
  simulation.convertStartState(readFile, writeFile, fileName);
  simulation.convertTransitionFunction(readFile, writeFile, fileName);
  simulation.convertAcceptState(readFile, writeFile, fileName);

  readFile.close();
  writeFile.close();

  return 0;
}
