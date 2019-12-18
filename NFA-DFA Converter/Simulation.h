/*
.
.
Simulation class
This is where all the magic happens
.
.
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include "FileIO.h"
#include "ListNodeSingle.h"
#include "SingleLinkedList.h"
#include "LO_States.h"
#include "LO_Symbols.h"
#include "SO_Accepts.h"
#include "StartState.h"
#include "TransitionFunc.h"
#include <iostream>
#include <fstream>

using namespace std;

class Simulation
{
private:
  string startStateSim;

public:
  //make methods for each variable (Q, E, F, ...)
  Simulation(); //constructor
  ~Simulation(); //destructor
  string getLine_NoNewLine(ifstream& readFile); //reads line without the newline
  string convertSetofStates(ifstream& readFile, ofstream& writeFile); //converts Set of States (Q)
  string convertListofSymbols(ifstream& readFile, ofstream& writeFile, string fileName); //converts alphabet (E)
  string convertTransitionFunction(ifstream& readFile, ofstream& writeFile, string fileName); //converts transition function
  string convertStartState(ifstream& readFile, ofstream& writeFile, string fileName); //converts start state
  string convertAcceptState(ifstream& readFile, ofstream& writeFile, string fileName); //converts accept state
};
#endif
