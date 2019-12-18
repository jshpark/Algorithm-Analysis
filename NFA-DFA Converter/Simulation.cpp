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
#include <algorithm>
#include <fstream>

using namespace std;

Simulation::Simulation()
{

}

Simulation::~Simulation()
{

}

string Simulation::getLine_NoNewLine(ifstream& readFile)
{
  string line;
  string newLine = "";
  getline(readFile, line);
  for (int i = 0; i < line.length(); ++i)
  {
    if ((line[i] != '\n') && (line[i] != '\r'))
    {
      newLine += line[i];
    }
  }
  newLine.erase(remove(newLine.begin(), newLine.end(), '{'), newLine.end());
  newLine.erase(remove(newLine.begin(), newLine.end(), '}'), newLine.end());
  return newLine;
}

string Simulation::convertSetofStates(ifstream& readFile, ofstream& writeFile)
{
  string line = getLine_NoNewLine(readFile);
  LO_States setOfStates(line);
  setOfStates.Convert();
  writeFile << setOfStates.getNewState() << endl;
}

string Simulation::convertListofSymbols(ifstream& readFile, ofstream& writeFile, string fileName)
{
  string throwAwayLine;
  readFile.close();
  readFile.open(fileName);
  getline(readFile, throwAwayLine);
  string line = getLine_NoNewLine(readFile);
  LO_Symbols setOfSymbols(line);
  setOfSymbols.Convert();
  writeFile << setOfSymbols.getSymbols() << endl;
}

string Simulation::convertStartState(ifstream& readFile, ofstream& writeFile, string fileName)
{
  string throwAwayLine;
  readFile.close();
  readFile.open(fileName);
  getline(readFile, throwAwayLine);
  string line = getLine_NoNewLine(readFile);
  StartState startState(line);
  startState.Convert(readFile, fileName);
  startStateSim = startState.getNewStart();
  writeFile << startState.getNewStart() << endl;
}

string Simulation::convertTransitionFunction(ifstream& readFile, ofstream& writeFile, string fileName)
{
  string line = getLine_NoNewLine(readFile);
  TransitionFunc transFunc(line);
  transFunc.Convert(readFile, fileName, startStateSim);

}

string Simulation::convertAcceptState(ifstream& readFile, ofstream& writeFile, string fileName)
{
  string line = getLine_NoNewLine(readFile);
  SO_Accepts acceptStateObj(line);
  acceptStateObj.Convert(readFile, fileName);
  ifstream tempRead;
  tempRead.open("tempFile.txt");
  string templine;
  while(getline(tempRead, templine))
  {
    writeFile << templine << endl;
  }
  tempRead.close();
}
