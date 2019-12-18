/*
.
.
Start State (q 0)
.
.
*/

#ifndef STARTSTATE_H
#define STARTSTATE_H

#include <iostream>

using namespace std;

class StartState
{
private:
  string oldStart;
  string newStart;

public:
  StartState(string old_Data); //makes oldStart = old_Data
  string getNewStart(); //accessor for newStart
  void Convert(ifstream& readFile, string fileName); //converts NFA start state to DFA start state
};
#endif
